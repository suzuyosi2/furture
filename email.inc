<?php

//-- mail送信時にincludeする関数



//-- mail_bodyの改行文字を変更する	$p=1 \n $p=2 \r\n

function mail_br($t,$p){
	
	$t=trim($t);
	
	$t=mb_convert_kana ($t,"KV");
	
	$t=preg_replace(array("/\r\n/","/\r/"),"\n",$t);

	if($p==2){$t=preg_replace("/\n/","\r\n",$t);}

	return $t;
}





?>
