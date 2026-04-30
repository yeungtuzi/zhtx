#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	// 2026-04-30: unused variable commented out
	// object sword;

        set_name("牛魔王", ({ "niumo wang","niu","wang"}) );
	set("long",@LONG
        他就是传说中牛魔王了，自从被孙悟空一棒子打飞之后就再也没有听说过他的消息，
原来这厮躲在这里避难，长生不老他是不指望了，但现在他潜心钻研武学典籍，
一心要成为武林高手，司空晓风还真有本事把这个怪物弄到这里来。
LONG
	 );

        set("title",HIW"天下无敌，唯我牛牛"NOR);
           create_family("步玄派", 8, "八代弟子");
        set("max_gin", 5000);
        set("max_kee", 8000);                    
        set("max_sen", 5000);
        set("max_force",5000); 
	set("force",10000);
        set("force_factor",350);     
        set("combat_exp",29999999);
	set("cor",100);
        set("cps",100);
        set("bln",100);
        set("int",100);
        set("con",100);
        set("spi",100);
        set("wil",30);
        set("vis",30);
        set("fav",1);
        set("str",100);
        set("dex",100);
	set("age",35);

        set_skill("dugu-jiujian", 300);
        set_skill("dodge", 300);
        set_skill("mysterrier",300);
        set_skill("parry", 300);
        set_skill("sword",300);
        set_skill("force",300);
        set_skill("taiji-shengong",300);
        set_skill("qiankun-danuoyi",300);
        set_skill("jingang-quan",300);
        set_skill("banruo-zhang",300);
        set_skill("strike",300);
        set_skill("cuff",300);

        map_skill("force","taiji-shengong");
        map_skill("sword","dugu-jiujian");
        map_skill("parry","qiankun-danuoyi");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");
        map_skill("cuff","jingang-quan");
        map_skill("strike","banruo-zhang");

        prepare_skill("cuff","jingang-quan");
        prepare_skill("strike","banruo-zhang");
        set_temp("apply/damage",500);
        set_temp("apply/attack",200);
        set_temp("apply/armor",500);
        set_temp("apply/armor_vs_force",500);
        set("chat_chance",10);
        set("chat_msg", ({ 
                "牛魔王摸了摸自己的肚皮，想破了脑袋也搞不懂紫霞当初为什么不嫁给他。\n",
                "牛魔王抖了抖身上的牛虱，还是觉得哪里有点痒。\n"
        }) );
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
                (: perform_action,"move.hasten" :),
        }) );
        set("auto_heal",1);
	setup();

      carry_object("/d/qiankun/obj/kingring");
      carry_object("/d/qiankun/obj/jian2")->wield();
      if(random(8)==0)carry_object("d/xanadu/treasure/casket");
}                          

void init()
{
        set("shen",-1*this_player()->query("shen")/10);
	return;
}
                             
int killed_enemy(object ob)
{
        command("heng");
}
/*void heart_beat() {
   if (!query_temp("mystshadow") && is_fighting())
      command("perform po-throwing");
      ::heart_beat();
}
*/
int chat()
{
        add("force",10);
        receive_curing("kee",50);
        receive_curing("sen",50);
        receive_curing("gin",50); 
        ::chat();
}
