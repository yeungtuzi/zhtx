//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
int throw_dan();

void create()
{
        int lvl,t;
        set("level",6);
        set_name("雷颖", ({ "lei ying","lei"}) );
        set("long",HIG@LONG
雷颖是江南霹雳堂堂主雷震子的小女儿，从小就最受家人宠爱。
她长得非常乖巧，水灵的大眼睛一眨一眨的，是个仿佛永远长不
大的小姑娘。一笑起来嘴角就露出两个小酒窝。
她自己一个人怎么跑到这个可怕的森林里来了呢？一定是淘气从
家里跑出来的。
LONG NOR
         );
        set("gender", "女性" );
        set("title",HIW"霹雳"NOR + CYN"小公主"NOR);
        set("age",16);
        //set advanced skills
	    lvl=query("level");
        t=230+(6-lvl)*25;
        
        set_skill("finger", t+random(10));
        set_skill("force", t+random(10));
        set_skill("parry", t+random(10));
        set_skill("dodge", t+random(10));
        set_skill("blade", t+random(10));
        set_skill("strike", t+random(10));
        set_skill("yunu-jianfa", t+random(10));
        set_skill("xianyun", t+random(10));
        set_skill("yunu-xinfa", t+random(10));
        set_skill("iron-cloth", t+random(10));
        set_skill("jiuyin", t+random(10));

        map_skill("dodge", "xianyun");
        map_skill("move", "xianyun");
        map_skill("iron-cloth", "jiuyin");
        map_skill("sword", "yunu-jianfa");
        map_skill("parry", "yunu-jianfa");
	    map_skill("force", "yunu-xinfa");

        setup();
        set("per",40);
        set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({
                (: consider :),
                (: throw_dan:),
        }) );
        carry_object("/obj/cloth/cloth")->wear();
        carry_object("obj/weapon/sword")->wield();
        set("weapon_type","sword");
}                          

int throw_dan()
{
        object me,*all,ob;
        int i;

        me=this_object();
        all=me->query_enemy(); 
	    ob=new(__DIR__"obj/pilidan");
        ob->move(me);
        for(i=0;i<sizeof(all);i++)
        {
                if(userp(all[i]))
                {
                        ob->do_throw(all[i]);
                        break;
                }
        }
        return 1;
}
                             
int killed_enemy(object ob)
{
        command("?");
}                 
