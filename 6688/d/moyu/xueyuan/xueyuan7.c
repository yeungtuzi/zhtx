
inherit "/ldg/std/dyna_room.c";

void create()
{
	set("short", "雪原");
	set("long", @LONG
这里是一片无垠的雪地，天地之间一片苍茫，两行足迹远远地
延伸出去，似乎永无尽头。雪原上一片刺目亮光，充满了各式
各样的危险，每一种都可以至命。若是在雪原中迷失了方向，
饥渴和寒冷就足以至命。
LONG
	);
	
	setup();
}
