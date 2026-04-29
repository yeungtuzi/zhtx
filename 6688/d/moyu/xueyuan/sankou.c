// sankou.c
// by meteoric
#include <ansi.h>
inherit "/ldg/std/dyna_room.c";
void create()
{
        set("short","大雪山口");
        set("long",@LONG
群山环绕，四周积雪终年不化。不远处有一个山谷。
LONG );

        set("objects",([
        	"/d/moyu/npc/wolf_king.c":1,
        	__DIR__"npc/snow_wolf.c":4+random(4),
        	]));
        set("exits",  ([
        	"north":"/d/moyu/valley/valley_entrance",
        	]));
        set("blocks", ([
        	"north":"wolf king"
        	]));
        setup();
}