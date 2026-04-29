// /d/leigu/npc/laozhe1 在无崖子那里
#include <ansi.h>
inherit NPC;

void heal();
void create()
{
        set_name(CYN"无名老者"NOR, ({ "nonename oldman", "oldman"}));
        set("long", "一个老者，满脸红光，须眉皆白。\n");
        set("gender", "男性");
        set("age", 99);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
	set("per", 25);

        set("max_kee", 2000);
        set("max_gin", 500);
	set("max_sen", 500);

        set("force", 7000);
        set("max_force", 3500);

        set("force_factor", 165);

        set("combat_exp", 3600000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :)
        }));

	set_temp("apply/damage", 80);
	set_temp("apply/armor", 80);
	set_temp("apply/armor_vs_force", 200);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
	set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
	set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        setup();
        carry_object("/obj/weapon/bamboo_sword")->wield();
        carry_object("/obj/cloth")->wear();
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 165");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
