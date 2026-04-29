// bedroom.c 休息室
// By Masterall
inherit ROOM;
#include "/std/room/check_room_family.c"
void create()
{set("short", "休息室");
set("long", @LONG
这是间石洞相当宽敞，里面摆了几张躺椅，专门是侠客岛招待客人休息
的地方，为了不惊扰客人休息，仆从们都退了出去，安安静静的，连门外滴
水的声音都可以听到。
LONG
);
set("exits",(["east" : __DIR__"guan"]));
set("sleep_room", 1);
set("no_faint",1);
set("family","侠客岛");
set("no_fight", 1);
setup(); 
replace_program(ROOM);
} 
