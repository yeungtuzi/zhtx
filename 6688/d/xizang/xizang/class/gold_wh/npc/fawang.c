// /d/xizang/class/gold_wh/npc/fawang.c
// /kungfu/class/xueshan/fawang.c  金轮法王
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("金轮法王", ({ "jinlun fawang", "fawang" }));
        set("long",@LONG
他就是新加国师封号的密宗金轮派掌门人,札什伦布寺主持金轮法王.
LONG
        );
        set("title", HIY "国师" NOR);
        set("gender", "男性");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_kee", 5000);
        set("max_gin", 5000);
	set("max_sen", 5000);
        set("force", 4500);
        set("max_force", 4500);
        set("force_factor", 100);
        set("combat_exp", 3500000);
        set("score", 200000);
	set("shen", -200000);
        set_skill("force", 250);
        set_skill("banruo", 250);
        set_skill("dodge", 250);
        set_skill("unarmed", 230);
        set_skill("parry", 250);
        set_skill("hammer", 250);
        set_skill("literate", 110);
        set_skill("zang-buddhi", 300);
        set_skill("wuxinglun", 250 );
        map_skill("force", "banruo");
        map_skill("parry", "wuxinglun");
        map_skill("hammer", "wuxinglun");
        set_skill("move", 250);
        set_skill("yujiamu-quan", 250);
        map_skill("unarmed", "yujiamu-quan");
        map_skill("move", "shenkong-xing");
        map_skill("dodge", "shenkong-xing");
        set_skill("shenkong-xing", 230);
	set("marks/banruo_level", 11);

        create_family("密宗金轮派", 7, "掌门人");
        set("class", "lama");

        setup();
        carry_object(__DIR__"obj/jinlun")->wield();
        carry_object(__DIR__"obj/pao")->wear();
        add_money("gold",1);
}

void attempt_apprentice(object ob)
{
        command("smile");
        command("nod");
        command("say 你就随我学习佛法吧！");
        command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
}
