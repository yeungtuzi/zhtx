//with wisdomer.c for telling some secret to players by tlang
//teller.c

#include <ansi.h>
inherit NPC;

void greeting(object);

int dest();

void ask_pu();

void ask_chubi();
void ask_zhantie();
void ask_lingkong();
void ask_qixiu();
void ask_yilu();
void ask_zhenwu();


void create()
{
   set_name(YEL"江湖百晓生"NOR, ({"teller"}) );
   set("long", "据说他对江湖中事无所不知，无所不晓。\n");
   set("per", 30);
   set("int", 30);
   set("str", 30);
   set("gender", "男性");
   set("age", 20+random(60));
   set("combat_exp", 500000+random(1000000));
   set("max_force", 1500);
   set("force", 1500);

          set("inquiry",([
                "纵横兵器谱"    : (: ask_pu :),
                "出跸刀"    : (: ask_chubi :),
                "斩铁剑"    : (: ask_zhantie :),
                "七修剑"    : (: ask_qixiu :),
                "真武剑"    : (: ask_zhenwu :),
                "刈鹿刀"    : (: ask_yilu :),
                "灵空剑"    : (: ask_lingkong :),
        ]));

   set_skill("dodge", 150);
   set_skill("unarmed", 150);
   set_skill("parry", 150);
   set_skill("blade", 150); 
   set_skill("force", 100);
   set_skill("cibei-dao", 100);
   set_skill("xiaoyaoyou", 100);
   set_skill("hunyuan-yiqi", 100);
   map_skill("blade", "cibei-dao");
   map_skill("dodge", "xiaoyaoyou");
   map_skill("force", "hunyuan-yiqi");
   
   set("count",1);
   set("ask_pu_count",1);
   set("ask_chubi_count",1);
   set("ask_zhantie_count",1);
   set("ask_qixiu_count",1);
   set("ask_lingkong_count",1);
   set("ask_yilu_count",1);

   add("gold", 5);
   setup();
   carry_object("/obj/cloth/cloth")->wear();
   carry_object("/obj/weapon/blade")->wield();
   call_out("dest",600);
}

void init()
{       
   object ob=this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 5, ob);    
}

void greeting(object ob) 
{       
        if( !ob || environment(ob) != environment() ) return;
        command("say 如果你给我一些好处，我可以告诉你孙老儿的消息，他可\n
   以带你去了解秘密。\n");
   command("smile");
   call_out("greeting",120,ob);
}                                   

void accept_object(object who, object ob)
{
   object obj;
   
   obj=new("/obj/gf/secret/npc/wisdomer.c");

   if( query("count")<1 )
   {
           command("sigh");
           command("say 今天已经有人来过了。等下次吧。\n");        
                   return; 
   } else {
           if(!ob->query("money_id") || ob->value() <5000)
           {
           command("waggle "+who->query("id"));
           command("say 这一点点还不够我喝杯茶。哼！！！！\n");
                   return;
           }
           destruct(ob);
           switch(random(2))
           {
           case 0:
           command("say 孙老儿现在在苏州客栈。你可以去找他。\n");  
           obj->move("/d/suzhou/kezhan");
           add("count",-1);
           break;
           case 1:
           command("say 孙老儿现在在雪亭镇客栈。你可以去找他。\n");
           obj->move("/d/snow/inn");
           add("count",-1);
           break;
           default:
           command("say 孙老儿现在在西藏客栈。你可以去找他。\n");
           obj->move("/d/guanwai/inn");
           add("count",-1);
           break;
           }
   }
}

int dest()
{
   command("bye");
   destruct(this_object());
}

void ask_pu()
{
        object obj;
        obj=new(__DIR__"wisdomer.c");
        if (!query("ask_pu_count")) return;
        if (!this_player()->query_temp("weaponor1")) return;
        command("whisper " + this_player()->query("id") +" 这本兵器谱可不是我自己写的那本，这本是一个神仙写的，据说有通灵的作用，但是已经很久没有人提到过它了。");
        command("whisper " + this_player()->query("id") +" 你再去问问孙老头吧。这次免费告诉你他的行踪。孙老儿现在在雪亭镇客栈。你可以去找他。");
    obj->move("/d/snow/inn");
    add("ask_pu_count",-1);
        return;
}

void ask_chubi()
{
        object ding;
        if (!query("ask_chubi_count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        command("whisper " + this_player()->query("id") +" 我听说这把名扬天下的木刀被丁鹏用十万两黄金从一个收藏家那里买了去了。");
        command("whisper " + this_player()->query("id") +" 听说他买这把刀是为了找神刀山庄的庄主柳若松寻仇。");
        command("whisper " + this_player()->query("id") +" 眼下他正在四处寻找柳若松。");
        command("whisper " + this_player()->query("id") +" 但是这么多年过去了，柳若松早已改姓换名，消声匿迹了。连神刀山庄也都没有了，要找到他，谈何容易。");
        command("sigh");
        command("say 他们之间的恩怨牵扯到一把魔刀，说起来那故事就长了。");
        ding=new("/u/z/zephyr/dingpeng.c");
    ding->move("/d/xueshan/foot");
    add("ask_chubi_count",-1);
        return;
}

void ask_zhantie()
{
        if (!query("ask_zhantie_count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        command("whisper " + this_player()->query("id") +" 斩铁剑是魔教震教至宝。");
        command("whisper " + this_player()->query("id") +" 但是三十年前魔教被六大门派围攻之后，这柄剑就没有在江湖上出现过了。");
    add("ask_zhantie_count",-1);
        return;
}

void ask_qixiu()
{
        if (!query("ask_qixiu_count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        command("whisper " + this_player()->query("id") +" 七修剑据说是上古宝物，是一切邪魔的克星");
        command("whisper " + this_player()->query("id") +" 武当派开山祖师所用真武剑和七修剑相比乃是小巫见大巫了。");
    add("ask_qixiu_count",-1);
        return;
}


void ask_yilu()
{
        if (!query("ask_yilu_count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        command("whisper " + this_player()->query("id") +" 刈鹿刀取意“秦失其鹿，天下共逐，唯胜者得鹿而刈之。”");
        command("whisper " + this_player()->query("id") +" 因而犯皇家大忌，二十八年前被皇帝用重金购得欲毁之。");
        command("whisper " + this_player()->query("id") +" 幸亏其时刚好皇家有一个武学奇才，爱惜此刀，向皇帝保证不会让此刀再流落到江湖人手中，他本人也不惜放弃荣华富贵，不再自认皇族。");
        command("whisper " + this_player()->query("id") +" 此人江湖中大大有名，你去试试运气吧。");
    add("ask_yilu_count",-1);
        return;
}


void ask_lingkong()
{
        if (!query("ask_lingkong_count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        command("say 灵空剑？从来没有听过");
        command("hmm");
        command("doubt");
        command("duh");
        command("whisper " + this_player()->query("id") +" 莫非是大招寺的灵空上人的兵器？");
        command("whisper " + this_player()->query("id") +" 哦对了，以前我曾听一个铸造兵器的能工巧匠提到过有一柄古代的凶剑，但是名字是否叫做灵空，我就不清楚了。");
        this_player()->set_temp("ask_lingkong",1);
    add("ask_lingkong_count",-1);
        return;
}
void ask_zhenwu()
{
        if (!this_player()->query_temp("weaponor5")) return;
        command("whisper " + this_player()->query("id") +" 真武剑其实并非武当最强兵器。");
        command("whisper " + this_player()->query("id") +" 武当派的镇派之宝乃是真武大帝神剑。但是此剑已经被日月神教的高手盗走了。");
        this_player()->set_temp("zhenwudadijian",1);    
        return;
}

