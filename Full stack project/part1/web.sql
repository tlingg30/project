CREATE DATABASE trip_website;
USE trip_website;

CREATE TABLE Account(
    account_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    hash_password VARCHAR(255) NOT NULL,
    signup_date DATETIME,
    account_type VARCHAR(255)
);

INSERT INTO Account (first_name, last_name, email, hash_password, signup_date, account_type)
VALUES('Anonymous', ' ', 'Anonymous', 'Anonymous', SYSDATE(), 'user'),
      ('Alex', 'Johnson', 'alexJohnson@gmail.com', 'alexJohnson', SYSDATE(), 'user'),
      ('Susan', 'Connor', 'susanConnor@gmail.com', 'susanConnor', SYSDATE(), 'user'),
      ('Ronald', 'Barr', 'ronaldBarr@gmail.com', 'ronalBarr', SYSDATE(), 'manager'),
      ('Marie', 'Broadbet', 'marieBroadbet@gmail.com', 'marieBroadbet', SYSDATE(), 'user'),
      ('Melvin', 'Forbis', 'melvinForbis@gmail.com', 'melvinForbis', SYSDATE(), 'manager');

CREATE TABLE Trip(
    trip_id INT AUTO_INCREMENT PRIMARY KEY,
    duration INT NOT NULL,
    start_date DATETIME NOT NULL,
    end_date DATETIME NOT NULL,
    available_slots INT NOT NULL,
    title TEXT NOT NULL,
    description TEXT NOT NULL,
    price TEXT,
    manager_id INT NOT NULL,
    FOREIGN KEY (manager_id) REFERENCES Account(account_id) ON DELETE CASCADE
);

INSERT INTO Trip VALUES(1, 3, '2024-07-15T08:00:00.000', '2024-07-17T22:30:00.000', 20, 'Kangaroo Island Upgrade with Lunch and Dinner', 'This tour makes getting to the Kangaroo Island from Adelaide an easy and hassle-free experience.', '$149.99', 4);
INSERT INTO Trip VALUES(2, 4, '2024-06-12T08:00:00.000', '2024-06-15T22:30:00.000', 30, 'Marion Bay Trip with Optional Hotel Pickup', 'Experience one of the wonders of the natural world up close and personal. Explore the colorful world underneath the water', '$249.00', 6);

CREATE TABLE Address(
    trip_id INT PRIMARY KEY,
    location_name VARCHAR(255),
    city VARCHAR(255),
    state VARCHAR(255) NOT NULL,
    country VARCHAR(255) NOT NULL,
    FOREIGN KEY (trip_id) REFERENCES Trip(trip_id) ON DELETE CASCADE
);

INSERT INTO Address VALUES(1, 'Kangaroo Island', 'Kangaroo Island', 'South Australia', 'Australia');
INSERT INTO Address VALUES(2, 'Marion Bay', 'York Peninsula', 'South Australia', 'Australia');

CREATE TABLE Booking(
    booking_id INT PRIMARY KEY AUTO_INCREMENT,
    num_travelers INT NOT NULL,
    booking_date DATETIME NOT NULL,
    user_id INT NOT NULL,
    trip_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Account(account_id) ON DELETE CASCADE,
    FOREIGN KEY (trip_id) REFERENCES Trip(trip_id) ON DELETE CASCADE
);

INSERT INTO Booking VALUES(1, 2, SYSDATE(), 2, 1);
INSERT INTO Booking VALUES(2, 4, SYSDATE(), 3, 1);
INSERT INTO Booking VALUES(3, 4, '2024-06-01T04:31:33.000', 3, 2);
INSERT INTO Booking VALUES(4, 3, SYSDATE(), 5, 1);
INSERT INTO Booking VALUES(5, 3, '2024-06-05T09:24:07.000', 5, 2);

CREATE TABLE Feedback(
    feedback_id INT PRIMARY KEY AUTO_INCREMENT,
    title_feedback TEXT NOT NULL,
    comment TEXT NOT NULL,
    feedback_date DATETIME NOT NULL,
    user_id INT NOT NULL,
    trip_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Account(account_id) ON DELETE CASCADE,
    FOREIGN KEY (trip_id) REFERENCES Trip(trip_id) ON DELETE CASCADE
);

INSERT INTO Feedback VALUES(1, 'This trip was the most enjoyable our family has ever experienced.', 'It was a fantastic adventure with amazing locations and a great vessel. The service was excellent, and we were pleasantly surprised by the generous lunch. Highly recommended!!!', '2024-06-20T10:45:00.000', 3, 2);
INSERT INTO Feedback VALUES(2, 'Had a good time though the food could be better','The staff was friendly, the conditions were great, and the weather was beautiful. We thoroughly enjoyed our day without feeling rushed or left out—it was amazing. While the food did not meet our expectations, we still recommend the experience.', '2024-06-18T14:32:50.000', 5, 2);