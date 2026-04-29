// bedroom.c 休息室
// By Masterall
inherit ROOM;
#include "/std/room/check_room_family.c"
void create()
{set("short", "休息室");
set("long", @LONG
    这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物， 只有中间放着一
张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG
);
set("exits",(["west" : __DIR__"donglang"]));
set("sleep_room", 1);
set("no_faint",1);
set("family","乾坤教");
set("no_fight", 1);
setup(); 
replace_program(ROOM);
} 
