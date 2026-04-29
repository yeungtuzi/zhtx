//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"紫阳楼二楼"NOR);
	set("long", @LONG
紫阳楼是长安城里最有名的一个饭馆了。这里不但常常有京城里的
达官贵人的排场宴请，还每天接待着从各地慕名而来的游人。这儿
客人不少，正吃得开心呢, 墙上贴着宴请须知(note)。
LONG         
	);

	set("exits", ([ 
	  	"down" :__DIR__"zyl.c", 
		"up":	__DIR__"zyl3.c",
 
	]));   
	set("objects", ([
	__DIR__"npc/xian.c" : 1,
]));
        set("item_desc", ([ 
	 	"note"      : @LONG
     本店提供婚宴服务, 需夫妻同时到本店, 可向老板打听"酒席"，
     分为高、中、低三档，有 here 和 all两种规模，其中低档 
     5 gold 一桌，中档 10 gold 一桌，赠送婚纱一套，高档 
     20 gold 一桌，赠送婚纱一套，另免费拍摄婚纱照，每桌
     四人，请客官自行决定 (decide) 档次与规模。
     酒席设在三楼，参加婚礼者，可将喜帖交与冼老板，在婚礼中
     均可 toast 或 cheer 来祝贺，新人也可使用 toast 或 cheer 。

     未婚玩家, 请尝试qingke here 或 qingke all，每位 1 gold。
LONG
]));
	setup();
	
}
