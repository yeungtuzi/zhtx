#include <ansi.h>

inherit NPC;

void create()
{
    	set_name("鹿杖客", ({ "lu zhangke", "lu" }));
	set("long",@LONG
	他脸上如同罩着一层黑烟，一部稀稀朗朗的花白胡子，正是
玄冥二老之一的鹿杖客，他贪花好色，平生作恶多端，不知道这时候
怎么会在这里。
LONG        
	);

    	set("title",BLU"玄机老人"NOR);

	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 56);
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("per", 30);
	set("max_kee", 4500);
	set("max_gin", 3000);
	set("force", 8000);
	set("max_force", 6000);
	set("force_factor", 250);
	set("combat_exp", 10000000);
	set("score", 100);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("strike", 180);
	set_skill("parry", 180);
	set_skill("staff", 180);

	set_skill("xuanming-shenzhang", 200);
	set_skill("mo-shan-jue", 200);
	set_skill("tianmo-dafa", 200);	

	map_skill("force","tianmo-dafa");
	map_skill("dodge","mo-shan-jue");
	map_skill("move","mo-shan-jue");
	map_skill("parry","xuanming-shenzhang");
	map_skill("strike","xuanming-shenzhang");
	
	prepare_skill("strike","xuanming-shenzhang");
	
	setup();
	
        carry_object(__DIR__"obj/luzhang");
}
