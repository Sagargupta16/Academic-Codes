<html>

<body>
    <?php
    echo '<!DOCTYPE html>';
    $fname = $_POST['fname'];
    $lname = $_POST['lname'];
    $mail = $_POST['mail'];
    $mob = $_POST['mobile'];
    $add = $_POST['add'];
    $pswrd = $_POST['pswrd'];
    echo "First Name : " . $fname;
    echo '<br>';
    echo "Last Name : " . $lname;
    echo '<br>';
    echo "Email-ID : " . $mail;
    echo '<br>';
    echo "Mobile No. : " . $mob;
    echo '<br>';
    echo "Address : " . $add;
    echo '<br>';
    echo "Password : $pswrd";
    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "test";
    $conn = mysqli_connect($servername, $username, $password, $database);
    if (!$conn) {
        die("Sorry the connection was not established" . mysqli_connect_error());
    }
    $sql = "INSERT INTO `data` (`First_Name`, `Last_Name`, `Email`, `phone_number`, `Address`, `Password`) VALUES ('$fname',
'$lname', '$mail', '$mob', '$add', '$pswrd')";
    $result = mysqli_query($conn, $sql);
    if ($result) {
        echo '<br><br><p style="font-weight:bolder; font-size:25px; font-style:italic;">Record inserted in the
database</p>';
    } else {
        echo "Error";
        mysqli_error($conn);
    }
    mysqli_close($conn);
    echo '<br><br><br>';
    echo '<button style="width:200px; height:50px; border:2px solid black;
 border-radius:5px; background-color:brown; color:white; font-weight:bolder; cursor:pointer;"
onclick="history.go(-1);">Back to Login';
    ?>
</body>

</html>