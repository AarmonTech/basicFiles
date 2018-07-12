<?php
if(isset($_GET['bulb'])){
    $light = $_GET['bulb'];
    
    if($light == "on") {
      $file = fopen("bulb.txt", "w") or die("can't open file");
      fwrite($file, '1');
      fclose($file);
    } 
    else if ($light == "off") {
      $file = fopen("bulb.txt", "w") or die("can't open file");
      fwrite($file, '0');
      fclose($file);
    }

}

if(isset($_GET['temprature'])){

  $temprature = $_GET['temprature'];

  $file = fopen("temprature.txt", "w") or die("can't open file");
  fwrite($file, $temprature);
  fclose($file);

}

?>

<html>
  <head>      
    
    
    <title>LED for Shoolin</title>
  
  </head>
  <body>
        <a href="?bulb=on" >Turn On</a>
        <br />

        <a href="?bulb=off" >Turn Off</a>
        <br />

        <?php
        echo get_file_contents("temprature.txt")
        ?>

  </body>
</html>

