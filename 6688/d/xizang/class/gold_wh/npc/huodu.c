// /d/xizang/class/xueshan/npc/huodu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("霍都王子", ({ "huodu wangzi", "huodu" }));
        set("long", "他是金轮法王座下的第三弟子。深得法王的真传。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 38);
        set("int", 28);
        set("con", 30);
        set("max_kee", 1500);
        set("max_gin", 1500);
	set("max_sen", 1000);
        set("force", 1300);
        set("max_force", 1300);
        set("force_factor", 30);
        set("combat_exp", 900000);
        set("score", 100000);
	set("shen", -100000);
	set_skill("zang-buddhi", 50);
	set_skill("literate", 135);
        set_skill("force", 120);
	set_skill("banruo", 160);
        set_skill("cuff", 100);
        set_skill("yujiamu-quan", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set_skill("parry", 120);
        map_skill("force", "banruo");
        map_skill("parry", "yujiamu-quan");
        map_skill("cuff", "yujiamu-quan");
	create_family("布达拉宫", 8, "弟子");
        setup();
//        carry_object(__DIR__"obj/fansword")->wield();
        carry_object(OBJ_DIR"cloth")->wear();
}

