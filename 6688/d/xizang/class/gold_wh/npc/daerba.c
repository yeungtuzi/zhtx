// /daemon/class/xueshan/daerba.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("达尔巴", ({ "daerba" }));
        set("long", "他是金轮法王座下的第二弟子。深得法王的真传。\n");
        set("gender", "男性");
        set("age", 42);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 45);
        set("int", 15);
        set("con", 30);
        set("max_kee", 2500);
        set("max_gin", 2500);
	set("max_sen", 2500);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);
        set("combat_exp", 1000000);
        set("score", 150000);
	set("shen", -150000);
        set_skill("force", 150);
//        set_skill("banruo", 20);
        set_skill("banruo", 120);
        set_skill("move", 200);
        set_skill("yujiamu-quan", 200);
        set_skill("dodge", 100);
        set_skill("cuff", 180);
        set_skill("parry", 200);
        set_skill("hammer", 220);
        set_skill("wuxinglun", 200);
        map_skill("force", "banruo");
        map_skill("parry", "wuxinglun");
        map_skill("hammer", "wuxinglun");
        map_skill("cuff", "yujiamu-quan");
	create_family("布达拉宫", 8, "弟子");
        setup();
        carry_object(__DIR__"obj/chu")->wield();
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
