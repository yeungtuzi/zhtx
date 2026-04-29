
#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;


void create()
{
	set_name("韦一笑", ({"wei yixiao", "wei", "yixiao",}));
	set("long",
		"他是一只青翼大蝙蝠\n"
		"他的脸色灰扑扑的。\n"
	);

	set("title","明教" + YEL"护教法王" NOR);
	set("nickname",HIC "青翼蝠王" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 48);
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_kee", 3000);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
	set("force_factor", 150);

	set("combat_exp", 1000000);
	set("score", 1000000);

	set_skill("force", 150);
    	set_skill("dodge", 200);
    	set_skill("strike", 180);
	set_skill("parry", 150);
     	set_skill("hanbing-mianzhang", 180);
	set_skill("moni-xinfa", 150);
	set_skill("bat-steps", 200);

    	map_skill("force", "moni-xinfa");
    	map_skill("dodge", "bat-steps");
    	map_skill("strike", "hanbing-mianzhang");
    	map_skill("parry", "hanbing-mianzhang");
    	
	prepare_skill("strike","hanbing-mianzhang");

	create_family("明教",36,"弟子");

	setup();
	carry_object("/d/mingjiao/npc/obj/shenxue")->wear();

}

#include "fawang.h"
