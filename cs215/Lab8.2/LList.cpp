#include"LList.h"

LList::LNode::LNode()
{
  data = 0;
  next = NULL;
}

LList::LList()
{
  first = NULL;
  size = 0;
}

LList::LList (const LList & other)
{
  first = NULL;
  size = 0;
  for (LNode * n = other.first; n != NULL; n = n->next)
    InsertLast (n->data);
}
LList::~LList ()
{
  while (first)
    DeleteFirst();
}
LList & LList::operator = (const LList & other)
{
  if (this == &other)
    return * this;
  while (first)
    DeleteFirst();
  for (LNode * n = other.first; n != NULL; n = n->next)
    InsertLast (n->data);
  return * this;
}
bool LList::operator == (const LList & other)
{
  if (size != other.size)
    return false;
  LNode * n = first;
  LNode * m = other.first;
  while (n != NULL)
    {
      if (n->data != m->data)
	return false;
      n = n->next;
      m = m->next;
    }
  return true;
}
int LList::Size () const
{
  return size;
}
ostream & operator << (ostream & outs, const LList & L)
{
  if (L.first == NULL)
    return outs;
  outs << L.first->data;
  for (LList::LNode * n = L.first->next; n != NULL; n = n->next)
    outs << ' ' << n->data;
  return outs;
}

bool LList::InsertFirst(const int & value)
{
  LNode * np = new LNode;
  if(np == NULL)
    return false;
  np->data = value;
  np->next = first;
  first = np;
  size++;
  return true;
}

bool LList::InsertLast(const int & value)
{
  if (size == 0)
    return InsertFirst(value);
  LNode * np = new LNode;
  if (np == NULL)
    return false;
  np->data = value;
  LNode * last;
  for(last = first; last->next !=NULL; last = last->next);
  last->next = np;
  size++;
  return true;
}

bool LList::DeleteFirst()
{
  if (first == NULL)
    return false;
  LNode * np = first;
  first = first->next;
  delete np;
  size--;
  return true;
}

bool LList::DeleteLast()
{
  if (first == NULL)
    return false;
  if (size == 1)
    return DeleteFirst();
  LNode * last = new LNode;
  for(last = first; last->next->next !=NULL; last = last->next);
  last->next = NULL;
  size--;
  return true;
}
