# C-Movie-Recommendation-System

A C based movie recommendation system was made. In this movie recommendation system, users 
can rate the movies stored in an </br> external database and get movie recommendations based on 
the movie they rated and the ratings of the other users. A prediction of </br> their rating can 
then be generated from their results.

<u>A menu is displayed with 5 choices:</u>

1- Register a user </br>
2- Display all the movies in the movie databse </br>
3- Rate a movie if you're a user </br>
4- Get movie recommendation based on the movies you rated in choice 3 </br>
5- Exit the program </br>

For the first choice, users were asked to register. However, if that username was already included in the external database, <br/> a message was prompted
to the user to retry again until he finally enters a username not found in the database. This process was also done <br/>
with case-insensitiveness.

The second choice displays all the movies respecting this following format:<br/>
Name of Movie (genre) - rating

The third choice first verifies if the user is found in the database and lets the user rates a movie of his choice from 1 to 5.

The last choice first verifies if the user is found in the database and shows a list of movies that they recommend based on their ratings and gives a predicitions based on the other users who rated the movie.





