<?php
$konek  = mysqli_connect("localhost", "root", "", "websensor");
$nilai = $_GET["sensor"];
mysqli_query($konek, "update sensor set nilai_sensor='$nilai'");

?>