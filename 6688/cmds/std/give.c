
// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
  string target, item;
  object obj, who, *inv, obj2;
  int i, amount;

  if(!arg) return notify_fail("你要给谁什么东西？\n");

  if( sscanf(arg, "%s to %s", item, target)==2
  || sscanf(arg, "%s %s", target, item)==2 );
  else return notify_fail("你要给谁什么东西？\n");

  if(!objectp(who = present(target, environment(me))) || !living(who))
          return notify_fail("这里没有这个人。\n");
  if( who == me )
          return notify_fail("东西就在你身上啊。\n");

  if(sscanf(item, "%d %s", amount, item)==2) {
          if( !objectp(obj = present(item, me)) )
                  return notify_fail("你身上没有这样东西。\n");
                  //如果NPC接受之后no_keep, 那就给吧。这样任何东西都可以给任务。--flyaway
                  if( obj->query("no_drop") && !wizardp(me) && !who->no_keep(obj))
                          return notify_fail("这样东西不能随便给人。\n");
          if( !obj->query_amount() )
                  return notify_fail( obj->name() + "不能被分开给人。\n");
          if( amount < 1 )
                  return notify_fail("东西的数量至少是一个。\n");
          if( amount > obj->query_amount() )
                  return notify_fail("你没有那么多的" + obj->name() + "。\n");
          else if( amount == (int)obj->query_amount() )
                  return do_give(me, obj, who);
          else {

                  obj->set_amount( (int)obj->query_amount() - amount );
                  obj2 = new(base_name(obj));
                  obj2->set_amount(amount);
                  do_give(me, obj2, who);
                  if( !do_give(me, obj2, who)) {
                          obj->set_amount( (int)obj->query_amount() +
                                           amount );
                          destruct(obj2);
                          return(0);
                  } else return 1;
          }
  }

  if(arg=="all") {
          inv = all_inventory(me);
          for(i=0; i<sizeof(inv); i++) {
                  do_give(me, inv[i], who);
          }
          write("Ok.\n");
          return 1;
  }

  if(!objectp(obj = present(item, me)))
          return notify_fail("你身上没有这样东西。\n");
  return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
  // 2026-04-30: unused variable commented out
  // int tmp;
/* maybe not check obj is a problem dao 971223 */
  if (!obj) {
//                      log_file("ZERO_LOG",sprintf("%s %s\n",me->name() , who->name()));
          return(1);
  }
          if(  obj->query("no_drop") && !wizardp(me) && !who->no_keep(obj))
          return notify_fail("这样东西不能随便给人。\n");

  if( who->over_encumbranced() )
          return notify_fail( who->name() + "已经负荷过重，再也搬不动任何东西了。\n");

  notify_fail("看起来" + who->name() + "并不愿意收下这" + obj->query("unit")
          + obj->name() + "。\n");
  if( (!interactive(who) && !(who->accept_object(me, obj)))
  ||      who->query("env/no_accept") )
          return 0;
// added by cmy 971115: accept_object may have dest obj
  if ( ! obj) return 1;

if(wizardp(me) && !who->no_keep(obj))
     log_file("GIVE_LOG",sprintf("(%s)%s give %d %O to %s\n",ctime(time()), me->query("name"), obj->query_amount(),obj->short(), who->name()));



// if master have quest,it shouldn't keep it #thir
  if( who->no_keep(obj)) {
//                printf("destruct it\n");
          destruct(obj);
          return(1);
  }
  else {
  if( !userp(who) && obj->value() ) {
          message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
          destruct(obj);
          return 1;
  } else if( obj->move(who) ) {
          printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
                  obj->name());
          message("vision", sprintf("%s给你一%s%s。\n", me->name(),
                  obj->query("unit"), obj->name()), who );
          message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
                  obj->query("unit"), obj->name()), environment(me), ({me, who}) );
          return 1;
  }
  else return 0;
  }
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>

这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.

HELP
    );
    return 1;
}

