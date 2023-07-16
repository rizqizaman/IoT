-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: May 12, 2023 at 07:07 AM
-- Server version: 10.5.16-MariaDB
-- PHP Version: 7.3.32

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


-- --------------------------------------------------------

--
-- Table structure for table `panas_dingin`
--

CREATE TABLE `panas_dingin` (
  `id` int(100) NOT NULL,
  `Suhu_Panas` float(10,2) NOT NULL,
  `Kelembaban_Panas` float(10,2) NOT NULL,
  `Suhu_Dingin` float(10,2) NOT NULL,
  `Kelembaban_Dingin` float(10,2) NOT NULL,
  `Date_Time` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `panas_dingin`
--

INSERT INTO `panas_dingin` (`id`, `Suhu_Panas`, `Kelembaban_Panas`, `Suhu_Dingin`, `Kelembaban_Dingin`, `Date_Time`) VALUES
(1, 38.10, 40.00, 40.60, 39.10, '2023-04-30 17:38:55'),
(568, 39.10, 41.50, 40.20, 39.10, '2023-04-30 10:59:07'),
(569, 39.10, 41.50, 40.20, 39.10, '2023-04-30 11:00:15');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `panas_dingin`
--
ALTER TABLE `panas_dingin`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `panas_dingin`
--
ALTER TABLE `panas_dingin`
  MODIFY `id` int(100) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=570;
COMMIT;

