// /daemon/class/xueshan/sangjd.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("桑吉多", ({ "sangjiduo", "sang" }));
        set("long", "他是金轮法王座下的大弟子。深得法王的真传。\n");
        set("gender", "男性");
        set("age", 47);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 48);
        set("int", 18);
        set("con", 30);
        set("max_kee", 3500);
        set("max_gin", 3500);
	set("max_sen", 3000);
        set("force", 3300);
        set("max_force", 3300);
        set("force_factor", 50);
        set("combat_exp", 1900000);
        set("score", 150000);
	set("shen", -150000);
	set_skill("zang-buddhi", 50);
	set_skill("literate", 35);
        set_skill("force", 200);
        set_skill("banruo", 40);
	set_skill("mizong-xinfa", 160);
        set_skill("dodge", 100);
        set_skill("unarmed", 220);
        set_skill("parry", 220);
        set_skill("hammer", 250);
        set_skill("wuxinglun", 150);
        map_skill("force", "mizong-xinfa");
        map_skill("parry", "wuxinglun");
        map_skill("hammer", "wuxinglun");
        set_skill("move", 100);
        map_skill("dodge", "shenkong-xing");
        map_skill("move", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        set_skill("shenkong-xing", 100);
        set_skill("yujiamu-quan", 100);
	create_family("密宗金轮派", 8, "大喇嘛");
        setup();
        carry_object(__DIR__"obj/quan")->wield();
        carry_object(__DIR__"obj/pao2")->wear();
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
