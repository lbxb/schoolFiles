-- 1. Retrieve the names of all departure and arrival city pairs. Result has schema (origin,dest).

SELECT origin, dest FROM tripinfo;

-- 2. Retrieve the names of all crew members. Order the results first by their job and then by their last name
--(both ascending order). Result has schema (name, job).

SELECT name, job FROM crew ORDER BY job ASC, name ASC;

--3. Retrieve passenger names from trip 'greyhound 73' on November 19, 2019. Result has schema (name).
SELECT name FROM passenger WHERE EXISTS (SELECT * FROM reservation WHERE company = 'greyhound' 
AND tripnbr = 73 AND date = '2019-11-19');

--4. Retrieve the names of bus companies in the database that offer service in 'boston', without duplicates.
--Result has schema (company).

SELECT DISTINCT company FROM tripinfo WHERE origin = 'boston' OR dest = 'boston';

--5. Retrieve the names of cities where you can take a 'fungwah' bus to 'lasvegas'. Result has schema (city).

SELECT origin FROM tripinfo WHERE dest = 'lasvegas' AND company = 'fungwah';

--6. Retrieve the total number of drivers currently in the database. Result has schema (single integer value).

SELECT COUNT(name) FROM crew WHERE job = 'driver';

--7.  Retrieve the average, total, minimum, and maximum salaries for each job in the database. Result has
--schema (job, avg_salary, total_salary, min_salary, max_salary).

SELECT job, AVG(salary), SUM(salary), MIN(salary), MAX(salary) FROM crew;

--8. Retrieve the names of all bus companies and the total number of miles all of their buses will travel in the
--month of November 2019. Result has schema (company, miles).

SELECT tripinfo.company, tripmiles FROM departure, tripinfo WHERE date like'2019-11-%';

--9. Retrieve the total number of miles each individual bus will travel for all upcoming trips. Result has
--schema (busnbr,miles).

SELECT busnbr, SUM(tripmiles) FROM departure, tripinfo GROUP BY busnbr;

--10. Retrieve departures with no passengers. Result has schema (company, tripnbr, segnbr, date).

SELECT company, tripnbr, segnbr, date FROM departure as d WHERE NOT EXISTS (SELECT * FROM reservation AS r 
WHERE d.company = r.company 
AND d.tripnbr = r.tripnbr 
AND d.segnbr = r.segnbr 
AND d.date = r.date);

--11. Retrieve departures with no non-crew passengers. Result has schema (company, tripnbr, segnbr, date).

SELECT company, tripnbr, segnbr, date FROM departure as d WHERE NOT EXISTS (SELECT * FROM reservation AS r 
WHERE d.company = r.company 
AND d.tripnbr = r.tripnbr 
AND d.segnbr = r.segnbr 
AND d.date = r.date 
AND NOT EXISTS (SELECT * FROM crew WHERE crew.ssn = ssn));

--12. Retrieve crew members who drive buses from, to, or through 'chicago'. Result has schema (ssn, name).

SELECT ssn, name FROM crew NATURAL JOIN schedule NATURAL JOIN tripinfo WHERE tripinfo.origin = 'chicago' OR tripinfo.dest = 'chicago';

--13. Retrieve bus trips whose last segment ends in 'miami'. Result has schema (company, tripnbr, segnbr,
--orig, dest, etd, eta, tripmiles).

SELECT company, tripnbr, MAX(segnbr), origin, dest, etd, eta, tripmiles FROM tripinfo WHERE dest = 'miami' GROUP BY tripnbr;

--14. Retrieve crew members who never arrive or depart from 'losangeles' either as passengers or on duty.
--Result has schema (ssn, name).

SELECT ssn, name FROM crew WHERE NOT EXISTS(SELECT * FROM schedule, tripinfo WHERE (tripinfo.origin = 'losangeles' OR tripinfo.dest = 'losangeles') 
AND schedule.company = tripinfo.company 
AND schedule.tripnbr = tripinfo.tripnbr
AND schedule.ssn = crew.ssn 
AND schedule.segnbr = tripinfo.segnbr) 
AND NOT EXISTS (SELECT * FROM reservation, passenger, tripinfo WHERE (tripinfo.origin = 'losangeles' OR tripinfo.dest = 'losangeles') 
AND crew.ssn = passenger.ssn 
AND passenger.ssn = reservation.ssn 
AND reservation.company = tripinfo.company 
AND reservation.tripnbr=tripinfo.tripnbr 
AND reservation.segnbr = tripinfo.segnbr);

--15. Retrieve crew members who drive the same trip segments on which they are also passengers. (On
-- different dates, of course, hence different departure dates.) Result has schema (ssn, name).

SELECT crew.name, crew.ssn FROM crew, passenger, reservation, schedule WHERE crew.ssn = passenger.ssn 
AND crew.ssn = schedule.ssn 
AND passenger.ssn = reservation.ssn 
AND reservation.company = schedule.company 
AND reservation.tripnbr = schedule.tripnbr 
AND reservation.segnbr = schedule.segnbr 
AND EXISTS (SELECT * FROM reservation, schedule WHERE reservation.date = schedule.date);

--16. Retrieve passengers who book entire bus trips (that is, they take every segment of the trip on the same
--date). Result has schema (ssn, name, company, tripnbr, date).

CREATE VIEW busbois(addsegments, tripnbr, ssn, date, company)
AS SELECT SUM(segnbr), tripnbr, ssn, date, company
FROM reservation
GROUP BY tripnbr, ssn, date;

CREATE VIEW allsegment(segsum)
AS SELECT SUM(segnbr)
FROM tripinfo
GROUP BY tripnbr, company;

SELECT DISTINCT b.ssn, p.name, b.company, b.tripnbr, b.date FROM busbois b, allsegment t, passenger p, reservation r
WHERE b.ssn = p.ssn 
AND b.ssn = r.ssn 
AND b.addsegments = t.segsum;


--17. Retrieve non-crew passenger pairs where the first passenger takes at least every departure the second
--takes. Result schema (ssn, ssn).

SELECT DISTINCT  p1.ssn, p2.ssn  FROM  passenger AS p1, passenger AS p2, reservation AS r1,  reservation AS r2, 
departure AS d1,departure AS d2 WHERE NOT EXISTS (SELECT * FROM crew WHERE p2.ssn = crew.ssn) 
AND NOT EXISTS (SELECT * FROM crew where p1.ssn = crew.ssn ) 
AND p1.ssn = r1.ssn 
AND p1.ssn <> p2.ssn 
AND r1.company = d1.company 
AND r1.tripnbr = d1.tripnbr 
AND r1.segnbr = d1.segnbr 
AND r1.date = d1.date 
AND p2.ssn = r2.ssn 
AND r2.company = d2.company 
AND r2.tripnbr = d2.tripnbr 
AND r2.segnbr = d2.segnbr 
AND r2.date = d2.date 
AND d2.date= d1.date 
AND d2.company = d1.company 
AND d2.tripnbr = d1.tripnbr 
AND d2.segnbr = d1.segnbr;
 

--18. Retrieve non-crew passenger pairs where the first passenger takes none of the departures that the second
--takes. Result has schema (ssn, ssn).

 SELECT DISTINCT p1.ssn, p2.ssn  FROM  passenger AS p1, passenger AS p2, reservation AS r1,  reservation AS r2, departure AS d1,departure AS d2 
 WHERE NOT EXISTS (SELECT * FROM crew where p2.ssn = crew.ssn) 
 AND NOT EXISTS (SELECT * FROM crew WHERE p1.ssn = crew.ssn ) 
 
 AND r1.company = d1.company 
 AND r1.tripnbr = d1.tripnbr 
 AND r1.segnbr = d1.segnbr 
 AND r1.date = d1.date 
 AND r2.company = d2.company 
 AND r2.segnbr = d2.segnbr 
 AND r2.tripnbr = d2.tripnbr 
 AND r2.date = d2.date 
 AND d2.date<> d1.date 
 AND d2.company <> d1.company 
 AND d2.tripnbr <> d1.tripnbr 
 AND d2.segnbr <> d1.segnbr
 AND p2.ssn = r2.ssn
 AND p1.ssn = r1.ssn 
 AND p1.ssn <> p2.ssn;

--19. Retrieve non-crew passengers and the tripmiles that they will earn based on current reservations. Result
--has schema (ssn, tripmiles).

 SELECT passenger.name, tripinfo.tripmiles FROM passenger, tripinfo, departure, reservation WHERE NOT EXISTS(SELECT * FROM crew WHERE passenger.ssn = crew.ssn) AND 
 passenger.ssn = reservation.ssn 
 AND reservation.company = departure.company 
 AND reservation.segnbr = departure.segnbr 
 AND reservation.tripnbr = departure.tripnbr 
 AND departure.company = tripinfo.company 
 AND tripinfo.tripnbr = departure.tripnbr 
 AND departure.segnbr = tripinfo.segnbr
 AND reservation.date = departure.date ;


--20. Retrieve total non-crew passenger tripmiles adding the new miles from current reservations to their
--existing (already earned) tripmiles. Print each non-crew passenger with total tripmiles. Result has
--schema (ssn, tripmiles).

SELECT passenger.ssn, SUM(tripinfo.tripmiles) + passenger.miles FROM passenger , tripinfo, departure, reservation
WHERE NOT EXISTS(SELECT * FROM crew WHERE crew.ssn = passenger.ssn) AND passenger.ssn = reservation.ssn 
 AND departure.company = reservation.company  
 AND departure.tripnbr = reservation.tripnbr 
 AND departure.segnbr = reservation.segnbr 
 AND departure.date = reservation.date 
 AND departure.company = tripinfo.company 
 AND departure.tripnbr = tripinfo.tripnbr 
 AND departure.segnbr = tripinfo.segnbr 
 GROUP BY passenger.ssn;