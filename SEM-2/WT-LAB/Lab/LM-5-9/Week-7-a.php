<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>

<body>
    <h1>
        <?php
        $n = 323;
        $sum = 0;
        while ($n > 0) {
            $r = $n % 10;
            $sum += $r;
            $n = $n / 10;
        }
        echo "sum of individual digits are: $sum";
    ?>
    </h1>
</body>

</html>