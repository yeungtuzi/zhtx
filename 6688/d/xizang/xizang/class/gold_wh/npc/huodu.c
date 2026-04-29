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
	set_skill("mizong-xinfa", 160);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 100);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 100);
        set_skill("move", 100);
        set_skill("parry", 120);
        set_skill("dodge", "shenkong-xing");
        map_skill("force", "mizong-xinfa");
        map_skill("parry", "yujiamu-quan");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("move", "shenkong-xing");
	create_family("密宗金轮派", 8, "弟子");
        setup();
//        carry_object(__DIR__"obj/fansword")->wield();
        carry_object(OBJ_DIR"cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say 好,现在你就是我的弟子了！");
        command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
}
