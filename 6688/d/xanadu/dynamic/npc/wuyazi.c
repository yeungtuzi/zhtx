#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name(GRN"无崖子"NOR, ({ "wuya zi", "zi" }));
        set("title",MAG "逍遥派" NOR + YEL "掌门" NOR);
        set("nickname", CYN "天下无双" NOR);
        set("long", 
                "这就是逍遥派的掌门人,他琴棋书画，三教九流,无所不精，无所不能。\n"
        );

        set("gender", "男性");
        set("age", 25);
        set("attitude", "friendly");

        set("bln", 50);
        set("str", 80);
        set("cps", 100);
        set("per", 300);
        set("int", 300);
        set("kar", 300);

        set("max_kee", 8000);
        set("max_gin", 8000);
        set("gin", 8000);
        set("max_sen", 8000);
        set("atman", 3000);
        set("max_atman", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force", 10000);
        set("max_force", 1500);
        set("force_factor", 100);
        set("combat_exp", 10000000);

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: exert_function,"maxsan" :),
        }) );

        set_skill("force", 250);
        set_skill("huagong-dafa", 350);
        set_skill("dodge", 250);
        set_skill("lingboweibu", 250);
        set_skill("strike", 250);
        set_skill("douzhuanxingyi", 250);
        set_skill("xingxiu-duzhang", 250);
        set_skill("parry", 200);
        set_skill("staff", 200);
        set_skill("tianshan-zhang", 250);
        set_skill("literate", 250);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "lingboweibu");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("parry", "douzhuanxingyi");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
	
	set_temp("apply/armor",200);
	set_temp("apply/armor_vs_force",200);

	carry_object(__DIR__"obj/xiaoyaoring")->wear();
           if(random(100) < 20)     carry_object("/d/latemoon/obj/bracelet")->wear();
        setup();
        if(random(10)>2) carry_rnd_equip(4,5);
}

