//97.11,23
//create bye hacky
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("鹿清笃", ({
                "lu qingdu",
                "lu",
                "qingdu",
        }));
        set("long",
                "他是全真教尹志平门下第四代弟子，\n"
        );
        set("title", HIB"全真派"NOR+YEL"道童"NOR);
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "taoist");
        set("age", 18);
        set("shen_type", 0);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_kee", 300);
        set("max_gin", 300);
        set("force", 300);
        set("max_force", 300);
        set("enforce", 10);
        set("combat_exp", 5000);
        set("score", 100);
        set_skill("force", 20);     
       set_skill("dodge", 50);       
       set_skill("sword", 40);        
        set_skill("parry", 30);
        set_temp("parry/attack",20);
        set_temp("parry/damage",10);
        set_temp("parry/defense",20);
        
        
        create_family("全真派", 4, "弟子");
        setup();
        
        carry_object(__DIR__"obj/robe")->wear(); 
}
