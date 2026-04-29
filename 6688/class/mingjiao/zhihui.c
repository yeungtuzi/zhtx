inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("智慧法王", ({ "zhihui fawang", "fawang" }));

        set("title",GRN "波斯明教" NOR + YEL +"护教宝树王" NOR);
        set("long",
"他是波斯明教十二宝树王之一，率领波斯教众前来中土寻访圣女，并迎立新教主。\n");
        set("gender", "男性");
        set("age", 46);
        set("attitude", "peaceful");
        set("shen_type", -1);
	set("int",80);

        set("max_kee", 2000);
        set("max_gin", 1000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 100);
        set("combat_exp", 5000000);

        set_skill("force", 180);
        set_skill("moni-xinfa", 200);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("liuyun-steps", 200);
        set_skill("strike", 180);
        set_skill("fanwen", 200);
	set_skill("literate",200);
        set_skill("shenghuo-shengong", 150);
        set_skill("qiankun-danuoyi", 80);

        map_skill("force", "moni-xinfa");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("sword", "shenghuo-shengong");
        map_skill("dodge", "liuyun-steps");
        map_skill("strike", "shenghuo-shengong");
	prepare_skill("strike","shenghuo-shengong");
	
        create_family("明教", 19, "弟子");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();

}

