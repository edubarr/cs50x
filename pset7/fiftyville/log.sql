-- Get the name of the thief
SELECT name FROM people

-- Query courthouse
WHERE people.license_plate IN (
    -- Get the license plates from the parking lot in the timeframe
    SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
)

-- Query ATM
AND people.id IN (
    -- Get person_id from the ATM
    SELECT person_id FROM bank_accounts
    -- Join the bank account to grab the person_id
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    -- Check the address and time of the transaction
    WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND transaction_type = "withdraw" AND atm_transactions.atm_location = "Fifer Street"
)

-- Query phone
AND people.phone_number IN (
    -- Get the phone number from time and duration of the call
    SELECT caller FROM phone_call WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60
)

-- Query first flight
AND people.passport_number IN (
    -- Get the passport numbers of passengers from the first flight in the date
    SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour, minute ASC LIMIT 1)
);


-- Get the escape city
-- Get the city from the airport id
SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour, minute ASC LIMIT 1);


-- Get the accomplice's
SELECT name FROM people
-- Get phone number
WHERE phone_number IN (
    -- Get phone calls on the date of the crime and where the caller is the criminal
    SELECT receiver FROM phone_calls
    WHERE year = 2020 AND month = 7 AND day = 28 AND caller = (SELECT phone_number FROM people WHERE name = "Ernest") AND duration < 60);