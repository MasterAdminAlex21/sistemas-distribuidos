<?php
$dir_dest="upload/";
$fichero=$_FILES['archivo']['name'];
$num=$_POST['numero'];
if(move_uploaded_file($_FILES['archivo']['tmp_name'],$dir_dest.$fichero)){
	echo "archivo subido";

	//y aqui se hace el desmadre

if(	$fp=fopen("upload/".$_FILES['archivo']['name'],'r')){

	$cadena="";
	while(!feof($fp)){
		$cadena= $cadena.fgets($fp);	
	}
	fclose($fp);
	//echo "$cadena";
	//vamos a limpiar el archivot

	$quitar=array("á","é","í","ó","ú","=","!","¿","?","¡",",",".","-","_","—","(",")","{","}","[","]",":",";","/","\\","|","\"","'","+","@","<",">","#","&","%","*","©","…","«","»");
	$sust=array("a","e","i","o","u","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","");

	$texto=str_replace($quitar, $sust, $cadena);
	$cadena=strtolower($texto);
	//echo "$texto";
	if($fp=fopen("limpio/".$_FILES['archivo']['name'],'w')){
		fwrite($fp,$cadena);
		fclose($fp);
	}//*/
	$ex="./Timeout/Cliente $num limpio/".$_FILES['archivo']['name'];
	echo shell_exec("$ex");

}else{
	echo "no se pudo abrir";
}
	//shell_exec(cmd)

}else{
	echo "archivo no subido<br>";
	print_r($_FILES);

	echo "$fichero";
}
$elimina="rm upload/".$_FILES['archivo']['name'];
//echo "$elimina";
shell_exec("$elimina");
//	echo "<br>$elimina";
?>