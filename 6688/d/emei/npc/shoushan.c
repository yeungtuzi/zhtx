// emei npc 守山弟子
//--by bibi--

#include <ansi.h>
inherit NPC;

void create()
{
       set_name("守山弟子",({"shoushan dizi", "dizi", "shoushan"}));     
       set("gender","女性");
       set("long","这是一位峨眉派的守山弟子，\n小小年纪就担负着守卫山门的重任，\n可见功夫定然不凡！\n");
       set("max_kee" , 500);
       set("kee" , 500);
       set("max_gin" , 500);
       set("gin",500);
       set("max_force" , 800);
       set("force" , 1600);  
         set("combat_exp",10000);
       set_skill("force",50);
       set_skill("dodge",50);
       set_skill("parry",50);
       set_skill("sword",50);      
       set_skill("strike",50);  
       set_skill("fuliu-jian",50);
       set_skill("jinding-mianzhang",50);
       set_skill("zhutian",50);          
       set_skill("linji-zhuang",50);
       set("force_factor" , 70);
                 
       map_skill("dodge","zhutian");
       map_skill("parry","fuliu-jian");
       map_skill("sword","fuliu-jian");
       map_skill("strike","jinding-mianzhang");
       map_skill("force","linji-zhuang");

       create_family("峨嵋派", 6, "弟子");

       prepare_skill("jinding-mianzhang"); 
                                         
       setup();
       carry_object(__DIR__"obj/cloth")->wear();
       carry_object(__DIR__"obj/changjian")->wield();
}
 
