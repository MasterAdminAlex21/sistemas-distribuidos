<html>
<head><title>
 Ejemplo
</title></head>

<body>
 <?php 
  print("Este es un ejemplo de pagina");
  print("<br><br>Supongamos que es una pagina para saber la disponibilidad de un servidor a traves de su nombre o su ip <br><br>");
  ?>
  <form action="command.php" method="get">
    Nombre o ip: <input type="text" name="nombre"><br>
    <input type="submit" value="Enviar">
</form>

<?php 
 $comand=$_GET["nombre"];
 echo "<pre>".shell_exec("$comand")."</pre>";
 //shell_exec("$comando");
 ?><br>
</body>
</html>