/*弟子*/
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(CYN"青城弟子"NOR, ({"dizi"})  );
        set("gender", "男性" );
        set("age", 22);
            
        set("long",@LONG
 他是青城弟子,因为资质较好,故余沧海留在身边亲身指导.
LONG);

   
       set("combat_exp", 1000);
        

        set("chat_chance_combat", 60);

        set_skill("unarmed", 20);
        set_skill("sword", 20);
       
       create_family("青城派", 20, "弟子");

     
        setup();
        add_money("coin", 80);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

