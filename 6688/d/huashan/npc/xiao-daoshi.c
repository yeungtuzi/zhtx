//xiao-daoshi.c
inherit __DIR__"jian_npc.c";
#include <ansi.h>
void create()
{
       set_name("小道士", ({ "xiao daoshi", "daoshi","taoist" }) );
       set("title","守门人");
       set("combat_exp",random(30)*10000+100000);
       set("str",50);
       set("int",50);
       set("cor",50);
       set("cps",50);
       set("age",16);
       set("gender","男性");

       create_family("华山派剑宗",19,"弟子");
       set_skill("sword",random(50)+50);
       set_skill("huashan-jianfa",random(50)+50);
       set_skill("huashan-shenfa",random(50)+50);
       set_skill("poyu-quan",random(50)+50);
       set_skill("dodge",random(50)+50);
       set_skill("parry",random(50)+50);
       set_skill("cuff",random(50)+50);
       set("force_factor",50);
       set("max_force",500);
       set("force",500);

       map_skill("dodge","huashan-shenfa");
       map_skill("sword","huashan-jianfa");
       map_skill("cuff","poyu-quan");
       map_skill("parry","huashan-jianfa");
       prepare_skill("cuff","poyu-quan");

       setup();
       carry_object(OBJ_DIR+"weapon/sword.c")->wield();
       carry_object(__DIR__"obj/cyanrobe.c")->wear();
       add_money("silver",random(50)+50);
}

int killed_enemy(object ob)
{
	if(userp(ob))
       command("chat "+HIR"象"+ob->query("name")+"这种"+RANK_D->query_rude(ob)+"居然妄图擅闯西岳庙！"NOR);
    return 1;
}
