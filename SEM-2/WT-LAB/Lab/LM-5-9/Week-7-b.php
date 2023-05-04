<!DOCTYPE html>
<html>
    <head>
        <title></title>
    </head>

    <body>
        <h1>
            <?php
                $n=323;
                $t=$n;
                $rev=0;
                while($n>0){
                    $r=$n%10;
                    $rev=$rev*10+$r;
                    $n=(int)($n/10);
                }
                echo "Reverse digits are: $rev <br>";
                if($t==$rev)
                echo "$rev is a Palindrome";
                else
                echo "$rev is not a Palindrome";
            ?>
        </h1>
    </body>
</html>