//ROOM:/d/hangzhou/shuidi.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

void create()
{                           
	set("short", RED"西湖水底"NOR);
	set("long", @LONG
   	  你四周是一个美丽的水下世界，各种鱼游来游去，美丽的水草在水中漂来
漂去。前面有一座雄伟的建筑，你真怀疑自己来到了龙宫。
LONG                                
	); 
	set("exits", ([
		"up" : __DIR__"hsting",
		"enter" : __DIR__"yuefen",
]));
	set("outdoors", "shuidi");                                       
  	setup();
}              

