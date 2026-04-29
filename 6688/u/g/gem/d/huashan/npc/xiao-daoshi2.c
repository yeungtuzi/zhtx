//xiao-daoshi.c
inherit __DIR__"jian_npc.c";
#include <ansi.h>
void create()
{
       set_name("小道士", ({ "xiao daoshi", "daoshi","taoist" }) );
       set("title","勤奋好学");
       set("combat_exp",random(30)*10000+100000);
       set("str",50);
       set("int",50);
       set("cor",50);
       set("cps",50);
       set("age",16);
       set("gender","男性");
       set("chat_chance",2);
       set("chat_msg", ({
                "小道士口中吟哦有声：“道可道，非常道，名可名，非常名！”\n",
                "小道士盘膝坐下，开始默默修炼内力。\n",
        }) );

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

