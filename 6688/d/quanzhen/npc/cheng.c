//made by hacky
//date 97,11,24

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("程遥伽",({"cheng yaojia","cheng"}));
    set("title",HIB"全真派"NOR+GRN"女道长"NOR);
    set("age",21);
    set("gender","女性");
   
    set("str",20);
    set("int",25);
    set("con",21);
    set("attitude","friendly");

    set("max_kee",500);
    set("max_gin",500);
    set("max_force",500);
    set("force",500);
    set("enforce",20);
    
    set("combat_exp",50000);
    set("score",1000);

    set_skill("parry",60);
    set_skill("dodge",60);
    set_skill("sword",60);
    set_skill("quanzhen-jian",50);
    set_skill("cuff",50);
    set_skill("taoism",60);
    set_skill("fx-step",40);
    set_skill("xiantian-gong",40);
    set_skill("force",60);
    set_skill("literate",50);
    set_skill("yangxin-quan",40);


    map_skill("sword","quanzhen-jian");
    map_skill("force","xiantian-gong");
    map_skill("dodge","fx-step");
    map_skill("parry","quanzhen-jian");
    map_skill("cuff","yangxin-quan");

    setup();

    create_family("全真派",3,"弟子");

    carry_object(__DIR__"obj/whiterobe")->wear();
    carry_object(__DIR__"obj/sword")->wield();

}

void attempt_apprentice (object ob)
{
    if ( (string)ob->query("gender")!="女性")
     {
         command("say 我只收女徒");
      }
     else {
          command("smile");
          command("say 全真教就是少女伴,你肯来真是太好了");
          command("recruit " + ob->query("id") );
          
      ob->set("title",HIB"全真派"NOR+YEL"女道童"NOR);
    }
 } 

