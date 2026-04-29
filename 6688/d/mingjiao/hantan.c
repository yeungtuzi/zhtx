inherit ROOM;

#include <ansi.h>   

void create()
{
        set("short", HIG"碧水寒潭"NOR);
        set("long", @LONG
	这时北风正烈，只到潭边一站，已然寒气逼人，内力稍差的
便已觉得不大受用。潭水早已结成厚冰，望下去碧沉沉地，深不见底。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"down" : __DIR__"hsqtan5",
		"up" 	: __DIR__"tohsq7",
	]) );

/*        set("objects", ([
            CLASS_D("mingjiao") + "/popo" : 1,
	]) );
*/
        setup();

}

void init()
{
	object me;
	 me = this_player();

	if ( (int)me->query_skill("dodge", 1)<=100 && (int)me->query("gin")>=40 )
	{
		me->receive_damage("gin", 10);
		me->improve_skill("dodge", me->query("int"));
	}

}
