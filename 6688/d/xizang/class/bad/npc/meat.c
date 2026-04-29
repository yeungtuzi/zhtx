// /d/xizang/class/bad/npc/meat.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("渡肉长老", ({ "meat", "du rou zhanglao", "rou" }));
	set("title", HIY+"少林神僧"+NOR);
	set("gender", "男性" );
	set("age", 40);
	set("str", 29);
	set("cor", 29);
	set("cps", 22);
	set("int", 22);
	set("long", "他就是少林寺原来的主持渡肉长老\n");
	set("combat_exp", 2100000);
	set("attitude", "heroism");
	set("force", 3900);
	set("max_force", 3900);
	set("force_factor", 500);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 199);
	set_skill("move", 200);
	set_skill("force", 233);
	set_skill("shaolin-shenfa", 220);
	set_skill("jingang-quan", 220);
	set_skill("hunyuan-yiqi", 219);

	map_skill("move", "shaolin-shenfa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "jingang-quan");
	map_skill("parry", "jingang-quan");
	map_skill("force", "hunyuan-yiqi");

	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}
