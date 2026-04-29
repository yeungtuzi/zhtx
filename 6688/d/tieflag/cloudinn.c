#include <room.h>  
inherit ROOM;
int valid_enter(object ob) {
	if(!userp(ob)) return -1;
	if(wizardp(ob)) return 2;
	if(  ob->query("class") != "tieflag" ) {
		notify_fail("你不属于"+"铁血大旗门，不能进入铁血大旗门的休息室。\n");
		return -1;
	}
	else return 1;
}
void create()
{
  set("short","留云馆");
  set("long",@LONG
这里是常春岛的留客之所。虽然岛上很少有客人到来，但这里仍然是窗明几净，
很显然有人经常打扫。屋角一张大床，被褥铺的整整齐齐。屋子正中小桌上放着一把
茶壶，和一盘点心还有一个小哨。
LONG
  );
  	set("exits/south",__DIR__"island");
    set("objects", ([
    	"/obj/example/dumpling" : 2,
    	"/obj/example/teapot" :1,
    	__DIR__"obj/pipe" :1,
    ]) ); 
    set("resource/water",1);
    set("sleep_room",1);
    set("no_fight",1);
    set("no_faint",1);
    set("liquid/name","茶水");
    set("liquid/type", "water");
    set("liquid/drunk_apply",6);
  
	setup();
}
                  
