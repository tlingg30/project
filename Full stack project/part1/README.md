There are in total 4 pages: (1) index.html (Home Page), (2) Trips.html (filtering has travelled trips), (3) IndividualTrip.html (see feedback of each trip) and (4) Feedback.html (for travel manager to see all feedback).


Instruction to set up: mysql < web.sql . If there already exists a database, drop that database first using DROP DATABASE trip_website; then mysql < web.sql


There are 6 users already created in the database (id from 1 to 6) and 2 trips (Kangaroo Island trip - hasn't started yet, and Marion Bay trip - has already started and ended):


account_id 1: Anonymous (type: user)

account_id 2: Alex Johnson (type: user) - booked: Kangaroo Island

account_id 3: Susan Connor (type: user) - booked: Kangaroo Island, has travelled: Marion Bay

account_id 4: Ronald Barr (type: manager) - manage Kangaroo Island trip

account_id 5: Marie Broadbet (type: user) - booked: Kangaroo Island, has travelled: Marion Bay

account_id 6: Melvin Forbis (type: manager) - manage Marion Bay trip


*Note: when clicked on Log in button in nav bar in any page, the default log in user id is 3. If you want to log in different account, please change the url parameter to the respective id (e.g: http://localhost:8080/index.html?id=6)


1. index.html


Clicked on Home button reload the page, clicked on Trip button redirect to Trips.html, clicked to About button move to the About section in the middle of the Home page.

Clicked on Log in button will log in as user id 3 by default. It will then appear the user id as well as log out button. If logged in as manager, ie id=4 or id=6 then a Feedback button will appear.


2. Trips.html


Sort by 3 types of trips: (1) All trips, (2) Upcoming trips (3) Trips have travelled

If not logged in, then the page only show All trips and Upcoming trip sorting option. Clicked on Log in button to see Trips have travelled option appear.

Click on Sort button to see the result

Please ignore other sorting options (destination, duration etc) as its not in requirement.


3. IndividualTrip.html


This page is used to see the customer feedback of each trip

Note: Kangaroo island trips hasn't started yet therefore there isn't any review and user can't add review too

To add review, user must log in first, if not logged in, the add review section will be disable with red text saying user must log in first. Clicked on log in button in the nav bar of the page will enable the add review section

User has the option to posted as their name or as anonymous. When clicked on Post button, the page will reload and user can see the latest feedback posted at the start of the list.


4. Feedback.html


This page is used to see customers feedback most recent to least recent

The feedback button will only appear when user id is 4 or 6 ie: http://localhost:8080/index.html?id=4 or http://localhost:8080/index.html?id=6

Since I set the default id to 3 therefore, you will have to manually type in the id as above

Manager id 4 will have no feedback since the Kangaroo Island trip hasnt started yet. Manager id 6 will see 2 feedback for Marion Bay trip.
