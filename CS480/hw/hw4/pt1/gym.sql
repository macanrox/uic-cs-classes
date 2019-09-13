CREATE TABLE instructors (
	SSN BIGINT(9) PRIMARY KEY NOT NULL,
	name VARCHAR(40) NULL,
	birthday DATE NULL,
	email VARCHAR(40) NULL,
	phoneNumber BIGINT(10) NULL
);

CREATE TABLE activities (
	code INT PRIMARY KEY NOT NULL
);

CREATE TABLE cardio (
	code INT PRIMARY KEY NOT NULL,
	name VARCHAR(40) NULL,
	level VARCHAR(40) NULL,
	tools VARCHAR(40) NULL,
	FOREIGN KEY code REFERENCES activities(code)
);

CREATE TABLE body_building (
	code INT PRIMARY KEY NOT NULL,
	FOREIGN KEY code REFERENCES activities(code)
);

CREATE TABLE activity_schedule (
	code INT PRIMARY KEY NOT NULL,
	day DATE NULL,
	startTime TIME NULL,
	endTime TIME NULL,
	instructor VARCHAR(40) NULL,
	room VARCHAR(40) NULL,
	FOREIGN KEY code REFERENCES activities(code),
	FOREIGN KEY instructor REFERENCES instructors(name)
);

CREATE TABLE members (
	memberID VARCHAR(40) PRIMARY KEY NOT NULL,
	name VARCHAR(40) NULL,
	birthday DATE NULL,
	type VARCHAR(40) NULL,
	membership DATE NULL
);

CREATE TABLE gym_use (
	memberID VARCHAR(40) PRIMARY KEY NOT NULL,
	day DATE NULL,
	entryTime TIME NULL,
	exitTime TIME NULL,
	FOREIGN KEY memberID REFERENCES members(memberID)
);

CREATE TABLE lockers (
	lockerID VARCHAR(10) PRIMARY KEY NOT NULL,
	memberID VARCHAR(40) NULL,
	FOREIGN KEY memberID REFERENCES members(memberID)
);

CREATE TABLE yearly_reservations (
	lockerID VARCHAR(10) PRIMARY KEY NOT NULL,
	startDate DATE NULL,
	endDate DATE NULL,
	fee DECIMAL(5,2),
	FOREIGN KEY lockerID REFERENCES lockers(lockerID)
);

CREATE TABLE semester_reservations (
	lockerID VARCHAR(10) PRIMARY KEY NOT NULL,
	startDate DATE NULL,
	endDate DATE NULL,
	fee DECIMAL(5,2),
	FOREIGN KEY lockerID REFERENCES lockers(lockerID)
);

CREATE TABLE one_time_reservations (
	lockerID VARCHAR(10) PRIMARY KEY NOT NULL,
	startTime TIME NULL,
	endTime TIME NULL,
	FOREIGN KEY lockerID REFERENCES lockers(lockerID)
);