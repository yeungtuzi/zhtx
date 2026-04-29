// emoted.c

#include <ansi.h>

inherit F_SAVE;

mapping emote;

//      The emote mapping contains the data base of emote definitions. Each emote
//      is defined in a sub-mapping with the following structure:
//
//      myself  - the message emoter will see
//      target  - the message the target will see when targeted
//      others  - the message others will see when no argument.
//
//      The emote mapping is indexed with the emote 'pattern' instead of emote
//      verb. For example, typing "smile" without argument will cause the daemon
//      search the emote mapping with "smile" as key, and typing "smile someone"
//      will cause the daemon search the emote mapping with "smile $" pattern as
//      the key, while $ means one argument.
//
//      In the message string, the following substitutions will be applied before
//      sending the messages:
//
//      $N              - name of emoter
//      $n              - name of target
//      $P              - pronoun of emoter
//      $p              - pronoun of target
//
//      Original by Annihilator@ESII (11/09/94)
//      $C              - very close call of emoter
//      $c              - close call of target
//      $R              - respect calling of target
//      $r              - rude calling of target
//      $S              - self calling of emoter
//      $s              - self-rude calling of emoter
//      aboved added by Xiang@XKX


void check_emote_list()
{
}

void create()
{
        if( !restore() && !mapp(emote) )
                emote = ([]);
        else
                check_emote_list();
}


string query_save_file() { return DATA_DIR + "emoted"; }

int save_back() {

        string src,dst;
        string id;
        id = geteuid();
        if( !id ) id = getuid();
        if( !stringp(id) ) return 0;
        src = query_save_file();
        dst = src + ".bak.o";
        src = src + ".o";
        cp ( src , dst ) ;
        return 1;
}

int remove()
{
        save();
        save_back();
        return 1;
}

// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
varargs mixed do_emote(object me, string verb, string arg, int channel_emote)
{
        string str, my_gender, target_gender, msg_postfix;
        object target;

        if( !environment(me) ) return 0;

        if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;

        // Determine the pattern to be searched and the target.
        if ( stringp(arg) && arg != "" ) {
                target = present(arg, environment(me));

                if(!objectp(target)) {
                        // If not channel emote, only search target in our environment.
                        if(!channel_emote) return 0;
                        target = find_player(arg);
                        if( !objectp(target) ) return 0;
                }
                
                if( !target->is_character() )
                        return notify_fail("你要对谁做这个动作？\n");           
                if( !me->visible(target) )
                        if( !wiz_level(target) && !raw_wiz_level(target) )
                                return notify_fail("你要对谁做这个动作？\n"); 
                        else
                                return 0;
                target_gender = target->query("gender");
                if( target==me ) {
                        msg_postfix = "_self";
                        target = 0;
                } else msg_postfix = "_target";
        } else msg_postfix = "";

        my_gender = me->query("gender");

        if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
                str = replace_string(str, "$N", me->name());
                str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                if( objectp(target) ) {
                        str = replace_string(str, "$C", RANK_D->query_self_close(target));
                        str = replace_string(str, "$c", RANK_D->query_close(target));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
                        str = replace_string(str, "$n", target->name());
                        str = replace_string(str, "$p", gender_pronoun(target_gender));
                }
                if( str[-1..-1] != "\n" ) str += "\n";
                if( !channel_emote ) message("emote", CYN + REPLACE_D->ansi_remove(str) + NOR, me);
        }
        if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
                str = replace_string(str, "$N", me->name());
                str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$C", RANK_D->query_self_close(target));
                str = replace_string(str, "$c", RANK_D->query_close(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
                str = replace_string(str, "$n", target->name());
                str = replace_string(str, "$p", gender_self(target_gender));
                if( str[-1..-1] != "\n" ) str += "\n";
                if( !channel_emote ) message("emote", CYN + REPLACE_D->ansi_remove(str) + NOR, target);
        }

        if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
                str = replace_string(str, "$N", me->name());
                str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                if( objectp(target) ) {
                        str = replace_string(str, "$C", RANK_D->query_self_close(target));
                        str = replace_string(str, "$c", RANK_D->query_close(target));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
                        str = replace_string(str, "$n", target->name());
                        str = replace_string(str, "$p", gender_pronoun(target_gender));
                }
                if( str[-1..-1] != "\n" ) str += "\n";
                if( !channel_emote ) message("emote", CYN + REPLACE_D->ansi_remove(str) + NOR, environment(me), ({me, target}));
                else return str;
        }

        // Let NPC know we are doing emote on him.
        if( objectp(target) ) target->relay_emote(me, verb);
        return str;
}

int set_emote(string pattern, mapping def)
{
        emote[pattern] = def;
        save();
        save_back();
        return 1;
}

int delete_emote(string pattern)
{
        map_delete(emote, pattern);
        save();
        save_back();
        return 1;
}

mapping query_emote(string pattern)
{
        if( !undefinedp(emote[pattern]) ) return emote[pattern];
        else return ([]);
}

string *query_all_emote()
{
        return keys(emote);
}

int creat_list()
{
    string *emote_keys ;
    int emote_num, i;
 
   string listfile="/data/emote_list";
   emote_keys = keys(emote);
   emote_num = sizeof(emote_keys);
   write_file(listfile,emote_num+"\n",1);
   for ( i = 0 ; i < emote_num ; i ++ ) {
      printf("%s\n",emote_keys[i]);
      if(i%10 == 0 )
          printf("Now : %d\n", i);
      write_file(listfile,emote_keys[i]+"\n",0);
      if (!undefinedp(emote[emote_keys[i]]["myself"]))
         write_file(listfile,emote[emote_keys[i]]["myself"],0);
      else
         write_file(listfile,"0\n",0);
      if (!undefinedp(emote[emote_keys[i]]["others"]))
         write_file(listfile,emote[emote_keys[i]]["others"]);
      else
         write_file(listfile,"0\n",0);
      if (!undefinedp(emote[emote_keys[i]]["myself_self"]))
         write_file(listfile,emote[emote_keys[i]]["myself_self"]);
      else
         write_file(listfile,"0\n",0);
      if (!undefinedp(emote[emote_keys[i]]["others_self"]))
         write_file(listfile,emote[emote_keys[i]]["others_self"]);
      else
         write_file(listfile,"0\n",0);
      if (!undefinedp(emote[emote_keys[i]]["myself_target"]))
         write_file(listfile,emote[emote_keys[i]]["myself_target"]);
      else
         write_file(listfile,"0\n",0);
      if (!undefinedp(emote[emote_keys[i]]["target"]))
         write_file(listfile,emote[emote_keys[i]]["target"]);
      else
         write_file(listfile,"0\n",0);
      if (!undefinedp(emote[emote_keys[i]]["others_target"]))
         write_file(listfile,emote[emote_keys[i]]["others_target"]);
      else
         write_file(listfile,"0\n",0);
   }
   return i;
}

