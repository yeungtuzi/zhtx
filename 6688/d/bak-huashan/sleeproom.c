//ROOM : /d/huashan/sleeproom.c
//Date: 97/1/1
#include <ansi.h>
inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", BLK "华山休息室" NOR);
        set("long", @LONG
这里是华山弟子饮食起居的地方。靠墙一溜摆着几张木床，床
上铺的是棉被。使人一看就想睡觉。
LONG
        );
        set("sleep_room",1);
	set("no_faint",1);
	set("no_fight",1);
	set("family","华山派");
        set("exits", ([
                  "north" : __DIR__"houhuayuan2",
        ]));
        
        setup();
}
