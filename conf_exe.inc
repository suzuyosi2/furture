<?php

include($_SERVER['DOCUMENT_ROOT'] .'/conf/unique/conf.inc');
include(SERVERROOT .'/conf/common/class/conf_class.inc');



/*
*	confクラス実行
*/
$conf=new ConfClass($confSet,$headerConfSet);
$conf->ConfClassSet();
$confSet=$conf->cs;		// $confSetの上書き


/*
*	DBとIPのセット
*/
if(is_array($confSet["DB"])){
	
	include("MDB2.php");	//pear DB読込
	include(SERVERROOT .'/conf/common/class/db_class.inc');
	include(SERVERROOT .'/conf/common/public/db.inc');
	
	$dbconf=new DbClass($conf);
	$dbconf->dbConnect();
	$dbconf->ipSet();
}


/*
*	AGENTのセット
*/
if($confSet["mobile"]!=false){
	include('Net/UserAgent/Mobile.php');
	$mobileUserAgent=Net_UserAgent_Mobile::singleton();
	$conf->mobileAgentSet($mobileUserAgent);
}
else{
	define("AGENT","PC");
}



/*
*	セッションのセット
*/

if($confSet["session"]!=false){
	include(SERVERROOT .'/conf/common/class/session_class.inc');
	$sesconf=new SessionClass($confSet["session"]);

	/*
	*	ログインのセット
	*/
	if($confSet["login"]!=false){
		include(SERVERROOT .'/conf/common/class/login_class.inc');
		$loginconf=new LoginClass($confSet["login"],$sesconf);
	}
}




/*
*	共有素材のセット
*/
if(is_array($confSet["share"])){
	$conf->ShareSet();
}


?>
