/* photoshoot.pl file for CS460 */

weather(monday,fair).
weather(tuesday,rainy).
weather(wednesday,cloudy).
weather(thursday,foggy).
weather(friday,sunny).
weather(saturday,snowy).
weather(sunday,fair).

weekend(saturday).
weekend(sunday).

sky(blue,Day) :- weather(Day,fair).
sky(blue,Day) :- weather(Day,sunny).
sky(white,Day) :- weather(Day,snowy).
sky(white,Day) :- weather(Day,foggy).
sky(grey,Day) :- weather(Day,rainy).

goodpictures(Day) :- sky(blue,Day),weekend(Day).
