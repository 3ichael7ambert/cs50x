-- List all tables in the database
.tables

-- Schema for crime_scene_reports
.schema crime_scene_reports

-- Finding the crime scene report for the theft
SELECT * FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Schema for flights
.schema flights

-- Finding flights departing on the day of the theft
SELECT * FROM flights
WHERE year = 2023 AND month = 7 AND day = 28;

-- Schema for passengers
.schema passengers

-- Finding passengers on the identified flights
SELECT * FROM passengers
WHERE flight_id IN (
    SELECT id FROM flights
    WHERE year = 2023 AND month = 7 AND day = 28
);

-- Schema for people
.schema people

-- Finding people details for those passengers
SELECT * FROM people
WHERE passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights
        WHERE year = 2023 AND month = 7 AND day = 28
    )
);

-- Schema for interviews
.schema interviews

-- Checking interviews for any mention of the theft or suspicious activities
SELECT * FROM interviews;

-- Schema for atm_transactions
.schema atm_transactions

-- Checking ATM transactions around the time of the theft
SELECT * FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28;

-- Schema for bank_accounts
.schema bank_accounts

-- Checking bank accounts for suspicious transactions
SELECT * FROM bank_accounts;

-- Schema for bakery_security_logs
.schema bakery_security_logs

-- Checking bakery security logs for suspicious activity on the day of the theft
SELECT * FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28;

-- Schema for phone_calls
.schema phone_calls

-- Checking phone calls made around the time of the theft
SELECT * FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28;
