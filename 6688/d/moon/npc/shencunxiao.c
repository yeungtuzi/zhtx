/**************************************************************************/
// $Id: shencunxiao.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

/*
   0: 向铁中堂打听云铿的事情
   1: 帮助盛存孝把解药送给柳荷衣(铁匠村东口的树下面的冷面少女）
   2: 把柳交给你的掌伤解药送给盛大娘。
   3: 盛存孝感激你，告诉你大家准备拜见再生草庐主人，你告知朱藻和水的婚事
   4: 盛存孝大惊，告诉你一段往事，原来朱和水是兄妹
   5: 你去阻拦该婚事，不得已和交战，战胜朱藻。
   6: 回到盛那里,领赏(可以学习断绝神功 duanjue-shengong)
   7: 去夜帝那里领赏(铁血的可以学习鬼斧神工tie_makeing，女id可以去拜朱老夫人为师，
      男玩家可以拜开山祖师铁为师，别的门牌则可以得到500两黄金) 
   8: 了解铁血的公案，奖励2 wlsw */
 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();
string ask_jieyao();
string finish_help();
string tell_story();
string ask_marry();
string ask_duanjue();

void create()
{
        set_name("盛存孝", ({ "shen cunxiao" , "shen" }) );

        set("nickname", MAG"紫心剑客"NOR);
        set("gender", "中性");
        set("age", 39);
        set("long",
                HIR"盛存笑,彩虹七剑之紫心剑客。\n" NOR
                "紫心剑客极为孝顺，曾经娶过三房妻子，前两任怀疑为其母所害，\n"
                "自从第三个妻子水柔颂去世以后，就没有再娶亲。紫心剑客剑法\n"
                "甚是高超，但是并非其家传武功，其为人厚道，深得江湖中人尊敬。\n"
                "他现在看起来非常忧虑，不知道又在为什么担心。\n"
            );
//46
        set("title",HIY "彩虹七剑" NOR);
        set("attitude", "peaceful");

        set("inquiry", ([
                "解药": (: ask_jieyao :),
                "盛大娘": (: finish_help :),
                "水柔颂": (: tell_story :),
                "shui rousong": (: tell_story :),
                "结婚": (: ask_marry :),
                "断绝神功": (: ask_duanjue :),
        ]) );

        set("str", 60);
        set("int", 60);
        set("cor", 60);
        set("cps", 60);
        set("per", 60);

        set("force", 22000);
        set("max_force", 11000);
        set("force_factor",150);
       set("max_mana",10000);
       set("max_atman",10000);
        set("combat_exp", 8500000);
        set("score", 500000); 
       set("max_kee",10000);
       set("max_gin",10000);
       set("max_sen",10000);
       set("kee",10000);
       set("gin",10000);
       set("sen",10000);
//       set("armor_vs_force", 100);
//       set("armor", 100);
        set("env/wimpy", 10);
        
        set("chat_chance", 2);
        set("chat_msg", ({
                HIM"那个姑娘没有母亲的解药，肯定会死的，该怎么办呢？\n" NOR,
                MAG"柔颂。。。。。。。。。。。。。。。。。。。\n" NOR,              
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set_skill("unarmed", 200);
        set_skill("force", 300);
        set_skill("parry",300);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("perception", 200);
        set_skill("literate",200);
        set_skill("duanjue-shengong",260);
        set_skill("shuangfei-zhangfa",250);
        set_skill("shuangfei-shenfa",250);
        set_skill("sword",300);

        set_skill("buddhism", 200);

        map_skill("unarmed", "shuangfei-zhangfa");
        map_skill("force", "duanjue-shengong");
       map_skill("dodge","shuangfei-shenfa");
       map_skill("sword","duanjue-shengong");
       map_skill("parry","duanjue-shengong");
        setup();
        carry_object("/d/moon/obj/zcloth")->wear();
        carry_object("/d/moon/obj/zsword")->wield();

}

string ask_jieyao()
{
  object ob;
  string obj;
  
  ob=this_player();
    
  command("say 刚才我母亲和一个青衣少女比武的时候，毒伤了那个姑娘，不知道你愿不愿意帮我把这解药送给那个姑娘?\n");
  command("say 如果你愿意帮忙的话就accept yes/accept no\n");
  
  obj=("/d/moon/obj/jieyao.c");
  (object) obj->move(ob);

  return "多谢了...\n";
}


string finish_help()
{
  object ob;
  ob=this_player();

  if (!ob->query("marks/ask_mastertie") || !ob->query("marks/finish_jieyao"))return "她是我母亲。。。\n";

    ob->set("marks/finish_save",1); 
    command("say 多谢您搭救了我母亲，我这次是受红鹰剑客兄妹的邀请，去再生草庐拜见其主人． \n");
 
}


string tell_story()
{
  message("sys",HIW"盛存孝垂首默然良久，似是在思量着该如何措词，又似是这故事委实令他伤心，是以他一时竟不忍出口。\n"NOR,users());
  message("sys",HIW"过了约莫盏茶功夫，他方自黯然将这故事说了出来。\n"NOR,users());
  command("say 昔日有个……有个某人，自幼酷好练武，但他只是个极为平凡之人，资质无超人之处，\n");
  command("say 是以虽然昼夜苦练，武功进境却仍不快。此人之母，望子成龙，却一心将他儿子当做绝世的天才,\n");
  command("say 只望她儿子将来必能成为不世出的大剑客。\n");
  command("say 某人既不忍令她母亲失望，但自己却又偏偏无法练成惊人的武功，其内心之痛苦，忍非他人所能体会。\n");
  command("say 他在这痛苦的煎熬下，终有一日，竟将那江湖中无人敢练的断绝神功开始练了起来。\n");
  command("say 此人天资总算不差，苦练三年，终于有所成就，但……但……却已将他生育子孙之能白白断送了，\n");
  command("say 他母亲也在无意间得知此事，悲痛惊惶之下，一面严禁爱子再练，一面立即忙着为他爱子成婚．\n");
  command("say 某人虽不肯以自己残废之身，来害别人大好女子之一生幸福，却又不敢违抗母亲之命。\n");
  command("say 只因他母亲终是抱着一线之希望，但……但某人成亲之后，两年毫无所出，他妻子却日渐憔悴了。\n");
  command("say 那时某人心中更是痛苦不堪，哪知他母亲对她爱子希望仍未断绝，竟将这不能生育之责，怪在她媳妇身上．\n");
  command("say 在如此情况下，某人的母亲，．．．．．竟然将她儿媳妇杀了.还要为她儿子另娶．\n");
  command("say 某人第二次成亲之后，生怕他母亲再……唉，于是便对他妻子时刻留意，处处保护。\n");
  command("say 但无论多么样的体贴与关心，也总是不能令正值青春的少妇……满意的，他第二个妻子，也日渐憔悴了.\n");
  command("say 没过多久，第二个妻子也去世了．他母亲又为他娶了第三个妻子.\n");
  command("say 如此过了两年，倒也平安无事，突然有一日，某人家族中不共戴大的仇家大举来犯，双方立时展开死战.\n");
  command("say 那媳妇亦是武林名家之后，武功颇不平常，掌中双股鸳鸯剑施展开来，已是武林一流名家的身手。\n");
  command("say 某人族中人丁不旺，仇家来犯，媳妇也不能坐视，手提双股鸳鸯剑，与仇家的一个少年子弟血战起来。\n");
  command("say 某人虽然在担心他媳妇与人交手经验不够，但自身已被对方两人缠住，一时之间，自是无法照顾他人。\n");
  command("say 等那一战结束，仇人全身而退时，但这时某人却也突然发觉，他的妻子竟已在恶战中失踪了，\n");
  command("say 某人焦急之下，立时前往寻找，他不敢惊动别人，只因他得知他母亲对这媳妇已有嫌弃之心，若是知道媳妇失踪，定不准别人去找的。\n");
  command("say 但一人之力终是有限，他过了半个多时辰后，方自寻至一片桃花林外……一片桃花林外……\n");
  message("sys",HIW"说到这里，他面色更是悲怆沉痛，连语声都已颤抖起来，似是这往昔的故事，直到此刻仍在刺着他的心。\n"NOR,users());
  message("sys",HIW"过了半晌，他方自缓缓接着说了下去。\n"NOR,users());
  command("say 那时月光满天，满林月影浮动，落花缤纷……而那桃花林中，却传出了一阵阵……一阵阵销魂之声。\n");
  command("say 某人虽非君子，亦非小人，听到这声音，立时顿住了脚步，方待转身离开，而那林中的销魂呻吟，已变成了呼唤\n");
  command("say 这呼唤一入某人之耳，他便己发觉竟是自他妻子口中所发。而他妻子口中呢声呼唤着的，正是他仇家少年的名字\n");
  command("say 某人惊骇悲怒之下，霍然转身，便待冲入桃花林，但冲了几步那悲愤之情却又不禁化做自责之心。\n");
  command("say 他想到这件事的发生，本是他自己铸下的大错，他妻子虽然不对，但他自己也并非完全没有责任。\n");
  command("say 一念至此，他全身都软了下去，立时没有了冲进去的勇气，竟倒在一株桃花树下再也难以爬起\n");
  command("say 他心身虽已疲乏，但目光却在无意中瞧见了那桃花林中的景象，这一瞧之下，他又骇得呆了\n");
  command("say 原来他妻子口中呼唤的虽是他仇家子弟的姓名，但是此刻正与他妻子……纠……纠缠的，却非那少年……\n");
  command("say 与他妻子纠缠的，竟是一位在武林中声名极响，但却以风流著名的江湖奇人。\n");
  command("say 他实在个懂那仇家少年怎会变作这江湖奇人，也猜不出这其间究竟序有什么曲折离奇的变化，一时间，竟呆住了。\n");
  command("say 等他定过神来，那奇人却似想起一件极为重要的事，竟突然离去，那身法之快，岂是人所能及\n");
  command("say 某人那时之心境，实是混杂着悲愤、自疚、诧异，成千成百种不同的情感，亦不知是酸是苦。\n");
  command("say 那时他实有一刀将他妻子杀却之心，但……但哪知他那妻子却在梦呓中叫出了他的名字。\n");
  command("say 这一声呼唤虽轻，但在他听来，却有如轰雷击顶。这时，他才知道，他妻子心底还是有着深情 \n");
  command("say 那时他便想到，他自己既是满身罪孽，他妻子的一时失足，他为何不能原谅？于是他不发一言，\n");
  command("say 将他妻子抱回家中，也未将此事向别人提起。往事己矣，我本也要将此事永远藏埋心底，哪知，\n");
  command("say 过了几个月，我才发觉她……她竟已有了身孕．\n");
  message("sys",HIW"说到最后，他终于还是漏了嘴，说出了“我”字，他身子不觉为之一震，倏然顿住了语声.\n"NOR,users());
  command("say 那媳妇，就是水灵光的母亲，而那奇人．．．就是夜帝. \n");

}

string ask_marry()
{

  
  object ob;
  ob=this_player();

  if (!ob->query("marks/finish_save")) return "那我们一起去吃酒吧\n";
  if (ob->query("marks/finish_persuade")) return "多谢你阻拦了他们的婚事，你愿意学我的断绝神功么？\n";
  if (ob->query("marks/finish_save"))
    {
      message("sys",HIR"盛存孝大惊.\n"NOR,users());
      command("say 朱藻和水灵光本是兄妹，万万不可结婚．\n");
      command("say 请你一定要去阻拦，我一定会重重报答你．\n");
    }

}


string ask_duanjue()
{

  object ob;

  ob=this_player();

  if (!ob->query("marks/finish_persuade")) return "........\n";
  if (ob->query("marks/finish_persuade")==1)
  {
    if(ob->query_skill("duanjue-shengong")==0)
      { 
       command("say 多谢你阻挡了这场人间惨剧，你可以去长春岛找到夜帝，这门小技在路上也许会有帮助.\n");
       message("sys","你听了盛存孝的讲解,领会了一点断绝神功的皮毛\n",users());
        ob->set_skill("duanjue-shengong",10);
       return "一路保重。。。\n";
      }
    return "你已经会这门功夫了，剩下的你自己好好体会吧。也许你能避免我的结局。\n";
  }
  if (ob->query("marks/finish_persuade")>1)
  {
    if(ob->query_skill("duanjue-shengong")==0)
     command("say 既然你不想学断绝神功，又来问我干吗呢？\n");
    return "哎。。。。。。。。。。。。。。\n";
  }
}















 


