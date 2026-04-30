// /obj/toy/case.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("机箱", ({ "case" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
        set("long","这是一个电脑机箱,你可以把其它零件装(fix)到里面.\n"+
                   "机箱里有张说明书(fixhelp),说明怎么装组装.\n"+
                   "请用fixhelp命令看说明书.\n");
        set("value", 18000);
        set("owner", "none");
        set("nature", "unfixed");
        set("f_level", 0);
        }
}
string query_autoload()
{
        object me;
        string target,casename;
        me = this_player();
        casename = present("case")->query("name");
        sscanf(casename, "%s的计算机" ,target);     
        return target;
}

void autoload(string arg)
{
        object who;
        // 2026-04-30: unused variable commented out
        // string f_status;
        int f_level;
        who = this_player();
        set("name",arg+"的计算机");
        if (f_level=who->query("marks/f_level"))
        set("f_level", f_level);
        if (f_level==6) set ("value", 700000);
        if (f_level==8) set ("value", 800000);
}

void init()
{
        add_action("do_fix", "fix");
        add_action("do_fixhelp", "fixhelp");
}

int do_fix(string arg)
{
        // 2026-04-30: unused variable commented out
        // string what;
        object who, ob;
        // 2026-04-30: unused variable commented out
        // int temp;
        if (!arg) return notify_fail("你要往机箱里装什么?\n");
        if ((this_object()->query("f_level") == 0) &&
        (arg != "board") && (arg != "mainboard") && (arg != "mother board") )
         return notify_fail("你得先把主板装上,才能装其它东西.\n");
        if (interactive(who=this_player())) {
          if ((arg == "board") || (arg =="mainboard") ||
              (arg != "mother board")) {
              if (!ob=present("mainboard",who))
               return notify_fail("你手里没有主板,去买一块吧.\n");
              ob->destruct();
              message_vision(BLU "$N把主板装进机箱.\n"NOR, who);
              who->set("marks/f_level", 1);
              set("f_level", 1);
          }
          if (arg == "cpu") {
              if (!ob=present("cpu",who))
               return notify_fail("你手里没有CPU,去买一个吧.\n");
              if (this_object()->query("f_level") != 1)
               return notify_fail("你还没把主板装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把CPU插到主板上.\n"NOR, who);
              who->set("marks/f_level", 2);
              set("f_level", 2);
          }
          if ((arg == "memory") || (arg == "ram")) {
              if (!ob=present("ram", who))
               return notify_fail("你手里没有内存,去买几条吧.\n");
              if (this_object()->query("f_level") != 2)
               return notify_fail("你还没把CPU装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把内存插到主板上.\n"NOR, who);
              who->set("marks/f_level", 3);
              set("f_level", 3);
          }
          if ((arg == "xianshika") || (arg == "displaycard") ||
              (arg == "svga") ) {
              if (!ob=present("displaycard", who))
               return notify_fail("你手里没有显示卡,去买一块吧.\n");
              if (this_object()->query("f_level") != 3)
               return notify_fail("你还没把内存装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把显示卡插在主板上.\n"NOR, who);
              who->set("marks/f_level", 4);
              set("f_level", 4);
          }
          if ((arg == "harddisk") || (arg == "hdd" )) {
              if (!ob=present("hdd", who))
               return notify_fail("你手里没有硬盘,去买一个吧.\n");
              if (this_object()->query("f_level") != 4)
               return notify_fail("你还没把显示卡装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把硬盘装进机箱.\n"NOR, who);
              who->set("marks/f_level", 5);
              set("f_level", 5);
          }
          if ((arg == "floppydisk") || (arg == "fdd" )) {
              if (!ob=present("fdd", who))
               return notify_fail("你手里没有软驱,去买一个吧.\n");
              if (this_object()->query("f_level") != 5)
               return notify_fail("你还没把硬盘装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把软驱装进机箱.\n"NOR, who);
              who->set("marks/f_level", 6);
              set("f_level", 6);
          }
          if ((arg == "soundcard") || (arg == "shengka")) {
              if (!ob=present("soundcard", who))
               return notify_fail("你手里没有声卡,去买一块吧.\n");
              if (this_object()->query("f_level") != 6)
               return notify_fail("你还没把软驱装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把声卡插在主板上.\n"NOR, who);
              who->set("marks/f_level", 7);
              set("f_level", 7);
          }
          if ((arg == "cddrive") || (arg == "guangqu")) {
              if (!ob=present("cddrive", who))
               return notify_fail("你手里没有光驱,去买一个吧.\n");
              if (this_object()->query("f_level") != 7)
               return notify_fail("你还没把声卡装好呢!\n");
              ob->destruct();
              message_vision(BLU "$N把光驱装进机箱.\n"NOR, who);
              who->set("marks/f_level", 8);
              set("f_level", 8);
          }
          if (query("f_level") ==6) {
              message_vision(HIG "$N自己装了一台计算机.\n"NOR, who);
              who->save();
              return 1;
          }
          if (query("f_level") >6) {
              message_vision(HIG "$N自升级多媒体计算机中.\n"NOR, who);
              who->save();
              return 1;
          }
        message_vision(HIG "$N忙于尝试自己装计算机中.\n"NOR, who);
        who->save();
        return 1;
        }
        return 1;
}

int do_fixhelp(string arg)
{
        object who;
        who=this_player();
        message_vision("说明书上写着:组装电脑,先主板,再CPU,然后内存,\n",who);
        message_vision("然后显示卡,硬盘,软驱,声卡,光驱(如果有的话).\n",who);
        return 1;
}

