<?php

$conn = mysqli_connect("localhost", "root", '', "esp32");

if (mysqli_connect_errno()) {
    die('Unable to connect to database ' . mysqli_connect_error());
}

$temperature = $_GET['temperature'];
$humidity = $_GET['humidity'];

$qry = $conn->prepare("INSERT INTO dht (temperature, humidity) VALUES ('" . $temperature . "','" . $humidity . "')");

if ($qry->execute()) {
    echo "Add Success";
} else {
    echo "Add Failed";
}
