-- MySQL dump 10.13  Distrib 5.7.9, for Win64 (x86_64)
--
-- Host: localhost    Database: bookstore1
-- ------------------------------------------------------
-- Server version	5.6.28-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `bookstore1`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `bookstore1` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `bookstore1`;

--
-- Table structure for table `author`
--

DROP TABLE IF EXISTS `author`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `author` (
  `id` int(5) NOT NULL,
  `name` varchar(84) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `books`
--

DROP TABLE IF EXISTS `books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `books` (
  `isbn` bigint(13) NOT NULL,
  `title` varchar(84) DEFAULT NULL,
  `price` decimal(5,0) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`isbn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `booksandauthors`
--

DROP TABLE IF EXISTS `booksandauthors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `booksandauthors` (
  `authorID` int(5) DEFAULT NULL,
  `isbnNumber` bigint(13) DEFAULT NULL,
  KEY `authorID_idx` (`authorID`),
  KEY `isbnNumber_idx` (`isbnNumber`),
  CONSTRAINT `authorID` FOREIGN KEY (`authorID`) REFERENCES `author` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `isbnNumber` FOREIGN KEY (`isbnNumber`) REFERENCES `books` (`isbn`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `orderhistory`
--

DROP TABLE IF EXISTS `orderhistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orderhistory` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `orderdate` timestamp NULL DEFAULT NULL,
  `userID` int(5) DEFAULT NULL,
  `isbn_number` bigint(13) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `userID_idx` (`userID`),
  KEY `isbn_number_idx` (`isbn_number`),
  CONSTRAINT `isbn_number` FOREIGN KEY (`isbn_number`) REFERENCES `books` (`isbn`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `userID` FOREIGN KEY (`userID`) REFERENCES `users` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2501 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(5) NOT NULL,
  `username` varchar(84) DEFAULT NULL,
  `password` varchar(84) DEFAULT NULL,
  `address` varchar(84) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Current Database: `bookstore2`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `bookstore2` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `bookstore2`;

--
-- Table structure for table `author`
--

DROP TABLE IF EXISTS `author`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `author` (
  `id` int(5) NOT NULL,
  `name` varchar(84) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `books`
--

DROP TABLE IF EXISTS `books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `books` (
  `isbn` bigint(13) NOT NULL,
  `title` varchar(84) DEFAULT NULL,
  `price` decimal(5,0) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`isbn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `booksandauthors`
--

DROP TABLE IF EXISTS `booksandauthors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `booksandauthors` (
  `authorID` int(5) DEFAULT NULL,
  `isbnNumber` bigint(13) DEFAULT NULL,
  KEY `authorID_idx` (`authorID`),
  KEY `isbnNumber_idx` (`isbnNumber`),
  CONSTRAINT `authorID` FOREIGN KEY (`authorID`) REFERENCES `author` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `isbnNumber` FOREIGN KEY (`isbnNumber`) REFERENCES `books` (`isbn`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `orderhistory`
--

DROP TABLE IF EXISTS `orderhistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orderhistory` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `orderdate` timestamp NULL DEFAULT NULL,
  `userID` int(5) DEFAULT NULL,
  `isbn_number` bigint(13) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `userID_idx` (`userID`),
  KEY `isbn_number_idx` (`isbn_number`),
  CONSTRAINT `isbn_number` FOREIGN KEY (`isbn_number`) REFERENCES `books` (`isbn`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `userID` FOREIGN KEY (`userID`) REFERENCES `users` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=25001 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(5) NOT NULL,
  `username` varchar(84) DEFAULT NULL,
  `password` varchar(84) DEFAULT NULL,
  `address` varchar(84) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Current Database: `bookstore3`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `bookstore3` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `bookstore3`;

--
-- Table structure for table `author`
--

DROP TABLE IF EXISTS `author`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `author` (
  `id` int(5) NOT NULL,
  `name` varchar(84) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `books`
--

DROP TABLE IF EXISTS `books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `books` (
  `isbn` bigint(13) NOT NULL,
  `title` varchar(84) DEFAULT NULL,
  `price` decimal(5,0) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`isbn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `booksandauthors`
--

DROP TABLE IF EXISTS `booksandauthors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `booksandauthors` (
  `authorID` int(5) DEFAULT NULL,
  `isbnNumber` bigint(13) DEFAULT NULL,
  KEY `authorID_idx` (`authorID`),
  KEY `isbnNumber_idx` (`isbnNumber`),
  CONSTRAINT `authorID` FOREIGN KEY (`authorID`) REFERENCES `author` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `isbnNumber` FOREIGN KEY (`isbnNumber`) REFERENCES `books` (`isbn`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `orderhistory`
--

DROP TABLE IF EXISTS `orderhistory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orderhistory` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `orderdate` timestamp NULL DEFAULT NULL,
  `userID` int(5) DEFAULT NULL,
  `isbn_number` bigint(13) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `userID_idx` (`userID`),
  KEY `isbn_number_idx` (`isbn_number`),
  CONSTRAINT `isbn_number` FOREIGN KEY (`isbn_number`) REFERENCES `books` (`isbn`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `userID` FOREIGN KEY (`userID`) REFERENCES `users` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=39095 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(5) NOT NULL,
  `username` varchar(84) DEFAULT NULL,
  `password` varchar(84) DEFAULT NULL,
  `address` varchar(84) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-04-29  7:04:24
