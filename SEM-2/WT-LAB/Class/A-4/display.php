<html>

<head>
    <link rel="stylesheet" href="style.css">
    <style>
        body {
            background-size: cover;
            color: white;
        }

        td,
        th {
            padding: 30px;
            border: 2px solid black;
            border-radius: 5px;
        }

        th {
            background-color: rgb(159, 0, 0);
            color: black;
            font-size: 20px;
        }

        td {
            text-align: center;
            background-color: coral;
            font-weight: bolder;
            font-size: 18px;
        }
    </style>
</head>

<body>
    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "test";
    echo "<table style='padding:40px; width:100%'>";
    echo '<tr>
 <th>Sl. No.</th>
 <th>First_Name</th>
 <th>Last_Name</th>
 <th>Email</th>
 <th>Mobile</th>
 <th>Address</th>
 <th>Password</th>
 </tr>';
    $conn = mysqli_connect($servername, $username, $password, $database);
    if (!$conn) {
        die('connection establishment failed ' . mysqli_connect_error());
    }
    $sql = "select * from data";
    $result = mysqli_query($conn, $sql);
    $i = 1;
    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            echo '<tr>
 <td>' . $i++ . '</td>
 <td>' . $row["First_Name"] . '</td>
 <td>' . $row["Last_Name"] . '</td>
 <td>' . $row["Email"] . '</td>
 <td>' . $row["phone_number"] . '</td>
 <td>' . $row["Address"] . '</td>
 <td>' . $row["Password"] . '</td>
 </tr>';
        }
    } else
        echo '0 records';
    ?>
</body>

</html>