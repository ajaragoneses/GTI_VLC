# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-1997, 2000-2007, 2009-2010 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
#
# This file can be copied and used freely without restrictions.  It can
# be used in projects which are not available under the GNU General Public
# License but which still want to provide support for the GNU gettext
# functionality.
# Please note that the actual code of GNU gettext is covered by the GNU
# General Public License and is *not* in the public domain.
#
# Origin: gettext-0.19
GETTEXT_MACRO_VERSION = 0.19

PACKAGE = vlc
VERSION = 3.0.0-git
PACKAGE_BUGREPORT = 

SED = /bin/sed
SHELL = /bin/sh


srcdir = ../../extras/package/win32/../../../po
top_srcdir = ../../extras/package/win32/../../..
VPATH = ../../extras/package/win32/../../../po

prefix = /home/gti/Escritorio/vlc_2/vlc/win32/_win32
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /home/gti/Escritorio/vlc_2/vlc/autotools/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, $(MKDIR_P) is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /home/gti/Escritorio/vlc_2/vlc/autotools/install-sh -d
install_sh = $(SHELL) ${SHELL} /home/gti/Escritorio/vlc_2/vlc/autotools/install-sh
MKDIR_P = /bin/mkdir -p
mkdir_p = $(MKDIR_P)

GMSGFMT_ = /usr/bin/msgfmt
GMSGFMT_no = /usr/bin/msgfmt
GMSGFMT_yes = /usr/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /usr/bin/msgfmt
MSGFMT_no = /usr/bin/msgfmt
MSGFMT_yes = /usr/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /usr/bin/xgettext
XGETTEXT_no = /usr/bin/xgettext
XGETTEXT_yes = /usr/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /usr/bin/msgmerge --update
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  $(srcdir)/ach.po $(srcdir)/af.po $(srcdir)/am.po $(srcdir)/an.po $(srcdir)/ar.po $(srcdir)/ast.po $(srcdir)/az.po $(srcdir)/be.po $(srcdir)/bg.po $(srcdir)/bn_IN.po $(srcdir)/bn.po $(srcdir)/br.po $(srcdir)/bs.po $(srcdir)/ca.po $(srcdir)/cgg.po $(srcdir)/ckb.po $(srcdir)/co.po $(srcdir)/cs.po $(srcdir)/cy.po $(srcdir)/da.po $(srcdir)/de.po $(srcdir)/el.po $(srcdir)/en_GB.po $(srcdir)/es.po $(srcdir)/et.po $(srcdir)/eu.po $(srcdir)/fa.po $(srcdir)/ff.po $(srcdir)/fi.po $(srcdir)/fr.po $(srcdir)/fur.po $(srcdir)/ga.po $(srcdir)/gd.po $(srcdir)/gl.po $(srcdir)/gu.po $(srcdir)/he.po $(srcdir)/hi.po $(srcdir)/hr.po $(srcdir)/hu.po $(srcdir)/hy.po $(srcdir)/ia.po $(srcdir)/id.po $(srcdir)/is.po $(srcdir)/it.po $(srcdir)/ja.po $(srcdir)/ka.po $(srcdir)/kk.po $(srcdir)/km.po $(srcdir)/kn.po $(srcdir)/ko.po $(srcdir)/ky.po $(srcdir)/lg.po $(srcdir)/lt.po $(srcdir)/lv.po $(srcdir)/mk.po $(srcdir)/ml.po $(srcdir)/mn.po $(srcdir)/mr.po $(srcdir)/ms.po $(srcdir)/my.po $(srcdir)/nb.po $(srcdir)/ne.po $(srcdir)/nl.po $(srcdir)/nn.po $(srcdir)/oc.po $(srcdir)/or.po $(srcdir)/pa.po $(srcdir)/pl.po $(srcdir)/ps.po $(srcdir)/pt_BR.po $(srcdir)/pt_PT.po $(srcdir)/ro.po $(srcdir)/ru.po $(srcdir)/si.po $(srcdir)/sk.po $(srcdir)/sl.po $(srcdir)/sq.po $(srcdir)/sr.po $(srcdir)/sv.po $(srcdir)/ta.po $(srcdir)/te.po $(srcdir)/tet.po $(srcdir)/th.po $(srcdir)/tl.po $(srcdir)/tr.po $(srcdir)/uk.po $(srcdir)/uz.po $(srcdir)/vi.po $(srcdir)/wa.po $(srcdir)/zh_CN.po $(srcdir)/zh_TW.po $(srcdir)/zu.po
GMOFILES =  $(srcdir)/ach.gmo $(srcdir)/af.gmo $(srcdir)/am.gmo $(srcdir)/an.gmo $(srcdir)/ar.gmo $(srcdir)/ast.gmo $(srcdir)/az.gmo $(srcdir)/be.gmo $(srcdir)/bg.gmo $(srcdir)/bn_IN.gmo $(srcdir)/bn.gmo $(srcdir)/br.gmo $(srcdir)/bs.gmo $(srcdir)/ca.gmo $(srcdir)/cgg.gmo $(srcdir)/ckb.gmo $(srcdir)/co.gmo $(srcdir)/cs.gmo $(srcdir)/cy.gmo $(srcdir)/da.gmo $(srcdir)/de.gmo $(srcdir)/el.gmo $(srcdir)/en_GB.gmo $(srcdir)/es.gmo $(srcdir)/et.gmo $(srcdir)/eu.gmo $(srcdir)/fa.gmo $(srcdir)/ff.gmo $(srcdir)/fi.gmo $(srcdir)/fr.gmo $(srcdir)/fur.gmo $(srcdir)/ga.gmo $(srcdir)/gd.gmo $(srcdir)/gl.gmo $(srcdir)/gu.gmo $(srcdir)/he.gmo $(srcdir)/hi.gmo $(srcdir)/hr.gmo $(srcdir)/hu.gmo $(srcdir)/hy.gmo $(srcdir)/ia.gmo $(srcdir)/id.gmo $(srcdir)/is.gmo $(srcdir)/it.gmo $(srcdir)/ja.gmo $(srcdir)/ka.gmo $(srcdir)/kk.gmo $(srcdir)/km.gmo $(srcdir)/kn.gmo $(srcdir)/ko.gmo $(srcdir)/ky.gmo $(srcdir)/lg.gmo $(srcdir)/lt.gmo $(srcdir)/lv.gmo $(srcdir)/mk.gmo $(srcdir)/ml.gmo $(srcdir)/mn.gmo $(srcdir)/mr.gmo $(srcdir)/ms.gmo $(srcdir)/my.gmo $(srcdir)/nb.gmo $(srcdir)/ne.gmo $(srcdir)/nl.gmo $(srcdir)/nn.gmo $(srcdir)/oc.gmo $(srcdir)/or.gmo $(srcdir)/pa.gmo $(srcdir)/pl.gmo $(srcdir)/ps.gmo $(srcdir)/pt_BR.gmo $(srcdir)/pt_PT.gmo $(srcdir)/ro.gmo $(srcdir)/ru.gmo $(srcdir)/si.gmo $(srcdir)/sk.gmo $(srcdir)/sl.gmo $(srcdir)/sq.gmo $(srcdir)/sr.gmo $(srcdir)/sv.gmo $(srcdir)/ta.gmo $(srcdir)/te.gmo $(srcdir)/tet.gmo $(srcdir)/th.gmo $(srcdir)/tl.gmo $(srcdir)/tr.gmo $(srcdir)/uk.gmo $(srcdir)/uz.gmo $(srcdir)/vi.gmo $(srcdir)/wa.gmo $(srcdir)/zh_CN.gmo $(srcdir)/zh_TW.gmo $(srcdir)/zu.gmo
UPDATEPOFILES =  ach.po-update af.po-update am.po-update an.po-update ar.po-update ast.po-update az.po-update be.po-update bg.po-update bn_IN.po-update bn.po-update br.po-update bs.po-update ca.po-update cgg.po-update ckb.po-update co.po-update cs.po-update cy.po-update da.po-update de.po-update el.po-update en_GB.po-update es.po-update et.po-update eu.po-update fa.po-update ff.po-update fi.po-update fr.po-update fur.po-update ga.po-update gd.po-update gl.po-update gu.po-update he.po-update hi.po-update hr.po-update hu.po-update hy.po-update ia.po-update id.po-update is.po-update it.po-update ja.po-update ka.po-update kk.po-update km.po-update kn.po-update ko.po-update ky.po-update lg.po-update lt.po-update lv.po-update mk.po-update ml.po-update mn.po-update mr.po-update ms.po-update my.po-update nb.po-update ne.po-update nl.po-update nn.po-update oc.po-update or.po-update pa.po-update pl.po-update ps.po-update pt_BR.po-update pt_PT.po-update ro.po-update ru.po-update si.po-update sk.po-update sl.po-update sq.po-update sr.po-update sv.po-update ta.po-update te.po-update tet.po-update th.po-update tl.po-update tr.po-update uk.po-update uz.po-update vi.po-update wa.po-update zh_CN.po-update zh_TW.po-update zu.po-update
DUMMYPOFILES =  ach.nop af.nop am.nop an.nop ar.nop ast.nop az.nop be.nop bg.nop bn_IN.nop bn.nop br.nop bs.nop ca.nop cgg.nop ckb.nop co.nop cs.nop cy.nop da.nop de.nop el.nop en_GB.nop es.nop et.nop eu.nop fa.nop ff.nop fi.nop fr.nop fur.nop ga.nop gd.nop gl.nop gu.nop he.nop hi.nop hr.nop hu.nop hy.nop ia.nop id.nop is.nop it.nop ja.nop ka.nop kk.nop km.nop kn.nop ko.nop ky.nop lg.nop lt.nop lv.nop mk.nop ml.nop mn.nop mr.nop ms.nop my.nop nb.nop ne.nop nl.nop nn.nop oc.nop or.nop pa.nop pl.nop ps.nop pt_BR.nop pt_PT.nop ro.nop ru.nop si.nop sk.nop sl.nop sq.nop sr.nop sv.nop ta.nop te.nop tet.nop th.nop tl.nop tr.nop uk.nop uz.nop vi.nop wa.nop zh_CN.nop zh_TW.nop zu.nop
DISTFILES.common = Makefile.in.in remove-potcdate.sin \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../../extras/package/win32/../../../include/vlc_access.h \
     ../../extras/package/win32/../../../include/vlc_aout.h \
     ../../extras/package/win32/../../../include/vlc_arrays.h \
     ../../extras/package/win32/../../../include/vlc_bits.h \
     ../../extras/package/win32/../../../include/vlc_block.h \
     ../../extras/package/win32/../../../include/vlc_block_helper.h \
     ../../extras/package/win32/../../../include/vlc_charset.h \
     ../../extras/package/win32/../../../include/vlc_codec.h \
     ../../extras/package/win32/../../../include/vlc_codecs.h \
     ../../extras/package/win32/../../../include/vlc_codec_synchro.h \
     ../../extras/package/win32/../../../include/vlc_common.h \
     ../../extras/package/win32/../../../include/vlc_config_cat.h \
     ../../extras/package/win32/../../../include/vlc_config.h \
     ../../extras/package/win32/../../../include/vlc_configuration.h \
     ../../extras/package/win32/../../../include/vlc_demux.h \
     ../../extras/package/win32/../../../include/vlc/deprecated.h \
     ../../extras/package/win32/../../../include/vlc_epg.h \
     ../../extras/package/win32/../../../include/vlc_es.h \
     ../../extras/package/win32/../../../include/vlc_es_out.h \
     ../../extras/package/win32/../../../include/vlc_events.h \
     ../../extras/package/win32/../../../include/vlc_filter.h \
     ../../extras/package/win32/../../../include/vlc_fixups.h \
     ../../extras/package/win32/../../../include/vlc_gcrypt.h \
     ../../extras/package/win32/../../../include/vlc_httpd.h \
     ../../extras/package/win32/../../../include/vlc_image.h \
     ../../extras/package/win32/../../../include/vlc_input.h \
     ../../extras/package/win32/../../../include/vlc_intf_strings.h \
     ../../extras/package/win32/../../../include/vlc_iso_lang.h \
     ../../extras/package/win32/../../../include/vlc_keys.h \
     ../../extras/package/win32/../../../include/vlc/libvlc_events.h \
     ../../extras/package/win32/../../../include/vlc/libvlc.h \
     ../../extras/package/win32/../../../include/vlc/libvlc_media_list.h \
     ../../extras/package/win32/../../../include/vlc/libvlc_structures.h \
     ../../extras/package/win32/../../../include/vlc/libvlc_vlm.h \
     ../../extras/package/win32/../../../include/vlc_main.h \
     ../../extras/package/win32/../../../include/vlc_md5.h \
     ../../extras/package/win32/../../../include/vlc_messages.h \
     ../../extras/package/win32/../../../include/vlc_meta.h \
     ../../extras/package/win32/../../../include/vlc_modules.h \
     ../../extras/package/win32/../../../include/vlc_mtime.h \
     ../../extras/package/win32/../../../include/vlc_network.h \
     ../../extras/package/win32/../../../include/vlc_objects.h \
     ../../extras/package/win32/../../../include/vlc_pgpkey.h \
     ../../extras/package/win32/../../../include/vlc_playlist.h \
     ../../extras/package/win32/../../../include/vlc_plugin.h \
     ../../extras/package/win32/../../../include/vlc_rand.h \
     ../../extras/package/win32/../../../include/vlc_services_discovery.h \
     ../../extras/package/win32/../../../include/vlc_sout.h \
     ../../extras/package/win32/../../../include/vlc_stream.h \
     ../../extras/package/win32/../../../include/vlc_strings.h \
     ../../extras/package/win32/../../../include/vlc_threads.h \
     ../../extras/package/win32/../../../include/vlc_tls.h \
     ../../extras/package/win32/../../../include/vlc_update.h \
     ../../extras/package/win32/../../../include/vlc_url.h \
     ../../extras/package/win32/../../../include/vlc_variables.h \
     ../../extras/package/win32/../../../include/vlc/vlc.h \
     ../../extras/package/win32/../../../include/vlc_vlm.h \
     ../../extras/package/win32/../../../include/vlc_vod.h \
     ../../extras/package/win32/../../../include/vlc_vout.h \
     ../../extras/package/win32/../../../include/vlc_vout_window.h \
     ../../extras/package/win32/../../../include/vlc_xml.h \
     ../../extras/package/win32/../../../src/audio_output/aout_internal.h \
     ../../extras/package/win32/../../../src/audio_output/common.c \
     ../../extras/package/win32/../../../src/audio_output/dec.c \
     ../../extras/package/win32/../../../src/audio_output/filters.c \
     ../../extras/package/win32/../../../src/audio_output/output.c \
     ../../extras/package/win32/../../../src/config/chain.c \
     ../../extras/package/win32/../../../src/config/cmdline.c \
     ../../extras/package/win32/../../../src/config/configuration.h \
     ../../extras/package/win32/../../../src/config/core.c \
     ../../extras/package/win32/../../../src/config/file.c \
     ../../extras/package/win32/../../../src/config/help.c \
     ../../extras/package/win32/../../../src/config/intf.c \
     ../../extras/package/win32/../../../src/config/keys.c \
     ../../extras/package/win32/../../../src/darwin/error.c \
     ../../extras/package/win32/../../../src/extras/libc.c \
     ../../extras/package/win32/../../../src/extras/tdestroy.c \
     ../../extras/package/win32/../../../src/input/access.c \
     ../../extras/package/win32/../../../src/input/clock.c \
     ../../extras/package/win32/../../../src/input/clock.h \
     ../../extras/package/win32/../../../src/input/control.c \
     ../../extras/package/win32/../../../src/input/decoder.c \
     ../../extras/package/win32/../../../src/input/decoder.h \
     ../../extras/package/win32/../../../src/input/decoder_synchro.c \
     ../../extras/package/win32/../../../src/input/demux.c \
     ../../extras/package/win32/../../../src/input/demux.h \
     ../../extras/package/win32/../../../src/input/es_out.c \
     ../../extras/package/win32/../../../src/input/es_out.h \
     ../../extras/package/win32/../../../src/input/input.c \
     ../../extras/package/win32/../../../src/input/input_internal.h \
     ../../extras/package/win32/../../../src/input/item.c \
     ../../extras/package/win32/../../../src/input/meta.c \
     ../../extras/package/win32/../../../src/input/stream.c \
     ../../extras/package/win32/../../../src/input/stream.h \
     ../../extras/package/win32/../../../src/input/stream_memory.c \
     ../../extras/package/win32/../../../src/input/subtitles.c \
     ../../extras/package/win32/../../../src/input/var.c \
     ../../extras/package/win32/../../../src/input/vlm.c \
     ../../extras/package/win32/../../../src/input/vlm_internal.h \
     ../../extras/package/win32/../../../src/input/vlmshell.c \
     ../../extras/package/win32/../../../src/interface/interface.c \
     ../../extras/package/win32/../../../src/libvlc.c \
     ../../extras/package/win32/../../../src/libvlc.h \
     ../../extras/package/win32/../../../src/libvlc-module.c \
     ../../extras/package/win32/../../../src/misc/block.c \
     ../../extras/package/win32/../../../src/misc/cpu.c \
     ../../extras/package/win32/../../../src/misc/error.c \
     ../../extras/package/win32/../../../src/misc/es_format.c \
     ../../extras/package/win32/../../../src/misc/events.c \
     ../../extras/package/win32/../../../src/misc/filter_chain.c \
     ../../extras/package/win32/../../../src/misc/image.c \
     ../../extras/package/win32/../../../src/misc/md5.c \
     ../../extras/package/win32/../../../src/misc/messages.c \
     ../../extras/package/win32/../../../src/misc/mtime.c \
     ../../extras/package/win32/../../../src/misc/objects.c \
     ../../extras/package/win32/../../../src/misc/rand.c \
     ../../extras/package/win32/../../../src/misc/threads.c \
     ../../extras/package/win32/../../../src/misc/update.c \
     ../../extras/package/win32/../../../src/misc/update.h \
     ../../extras/package/win32/../../../src/misc/variables.c \
     ../../extras/package/win32/../../../src/misc/variables.h \
     ../../extras/package/win32/../../../src/misc/xml.c \
     ../../extras/package/win32/../../../src/missing.c \
     ../../extras/package/win32/../../../src/modules/cache.c \
     ../../extras/package/win32/../../../src/modules/entry.c \
     ../../extras/package/win32/../../../src/modules/modules.c \
     ../../extras/package/win32/../../../src/modules/modules.h \
     ../../extras/package/win32/../../../src/network/getaddrinfo.c \
     ../../extras/package/win32/../../../src/network/httpd.c \
     ../../extras/package/win32/../../../src/network/io.c \
     ../../extras/package/win32/../../../src/network/rootbind.c \
     ../../extras/package/win32/../../../src/network/tcp.c \
     ../../extras/package/win32/../../../src/network/tls.c \
     ../../extras/package/win32/../../../src/network/udp.c \
     ../../extras/package/win32/../../../src/playlist/control.c \
     ../../extras/package/win32/../../../src/playlist/engine.c \
     ../../extras/package/win32/../../../src/playlist/item.c \
     ../../extras/package/win32/../../../src/playlist/loadsave.c \
     ../../extras/package/win32/../../../src/playlist/playlist_internal.h \
     ../../extras/package/win32/../../../src/playlist/search.c \
     ../../extras/package/win32/../../../src/playlist/services_discovery.c \
     ../../extras/package/win32/../../../src/playlist/sort.c \
     ../../extras/package/win32/../../../src/playlist/thread.c \
     ../../extras/package/win32/../../../src/playlist/tree.c \
     ../../extras/package/win32/../../../src/stream_output/sap.c \
     ../../extras/package/win32/../../../src/stream_output/sdp.c \
     ../../extras/package/win32/../../../src/stream_output/stream_output.c \
     ../../extras/package/win32/../../../src/stream_output/stream_output.h \
     ../../extras/package/win32/../../../src/text/iso-639_def.h \
     ../../extras/package/win32/../../../src/version.c \
     ../../extras/package/win32/../../../src/video_output/interlacing.c \
     ../../extras/package/win32/../../../src/video_output/video_output.c \
     ../../extras/package/win32/../../../src/video_output/video_text.c \
     ../../extras/package/win32/../../../src/video_output/video_widgets.c \
     ../../extras/package/win32/../../../src/video_output/vout_control.h \
     ../../extras/package/win32/../../../src/video_output/vout_internal.h \
     ../../extras/package/win32/../../../src/video_output/vout_intf.c \
     ../../extras/package/win32/../../../src/video_output/vout_subpictures.c \
     ../../extras/package/win32/../../../src/win32/thread.c \
     ../../extras/package/win32/../../../lib/audio.c \
     ../../extras/package/win32/../../../lib/core.c \
     ../../extras/package/win32/../../../lib/event.c \
     ../../extras/package/win32/../../../lib/libvlc_internal.h \
     ../../extras/package/win32/../../../lib/log.c \
     ../../extras/package/win32/../../../lib/media.c \
     ../../extras/package/win32/../../../lib/media_discoverer.c \
     ../../extras/package/win32/../../../lib/media_library.c \
     ../../extras/package/win32/../../../lib/media_list.c \
     ../../extras/package/win32/../../../lib/media_list_path.h \
     ../../extras/package/win32/../../../lib/media_list_player.c \
     ../../extras/package/win32/../../../lib/media_player.c \
     ../../extras/package/win32/../../../lib/playlist.c \
     ../../extras/package/win32/../../../lib/video.c \
     ../../extras/package/win32/../../../lib/vlm.c \
     ../../extras/package/win32/../../../modules/access/alsa.c \
     ../../extras/package/win32/../../../modules/access/archive/archive.c \
     ../../extras/package/win32/../../../modules/access/attachment.c \
     ../../extras/package/win32/../../../modules/access/avio.h \
     ../../extras/package/win32/../../../modules/access/bd/bd.c \
     ../../extras/package/win32/../../../modules/access/bluray.c \
     ../../extras/package/win32/../../../modules/access/cdda.c \
     ../../extras/package/win32/../../../modules/access/concat.c \
     ../../extras/package/win32/../../../modules/access/dc1394.c \
     ../../extras/package/win32/../../../modules/access/dcp/dcp.cpp \
     ../../extras/package/win32/../../../modules/access/decklink.cpp \
     ../../extras/package/win32/../../../modules/access/directory.c \
     ../../extras/package/win32/../../../modules/access/dshow/crossbar.cpp \
     ../../extras/package/win32/../../../modules/access/dshow/dshow.cpp \
     ../../extras/package/win32/../../../modules/access/dshow/filter.cpp \
     ../../extras/package/win32/../../../modules/access/dshow/filter.h \
     ../../extras/package/win32/../../../modules/access/dsm/access.c \
     ../../extras/package/win32/../../../modules/access/dtv/access.c \
     ../../extras/package/win32/../../../modules/access/dv.c \
     ../../extras/package/win32/../../../modules/access/dvdnav.c \
     ../../extras/package/win32/../../../modules/access/dvdread.c \
     ../../extras/package/win32/../../../modules/access/eyetv.m \
     ../../extras/package/win32/../../../modules/access/file.c \
     ../../extras/package/win32/../../../modules/access/fs.c \
     ../../extras/package/win32/../../../modules/access/ftp.c \
     ../../extras/package/win32/../../../modules/access/gnomevfs.c \
     ../../extras/package/win32/../../../modules/access/http.c \
     ../../extras/package/win32/../../../modules/access/idummy.c \
     ../../extras/package/win32/../../../modules/access/imem.c \
     ../../extras/package/win32/../../../modules/access/imem-access.c \
     ../../extras/package/win32/../../../modules/access/jack.c \
     ../../extras/package/win32/../../../modules/access/linsys/linsys_hdsdi.c \
     ../../extras/package/win32/../../../modules/access/linsys/linsys_sdi.c \
     ../../extras/package/win32/../../../modules/access/live555.cpp \
     ../../extras/package/win32/../../../modules/access/mms/asf.c \
     ../../extras/package/win32/../../../modules/access/mms/asf.h \
     ../../extras/package/win32/../../../modules/access/mms/buffer.c \
     ../../extras/package/win32/../../../modules/access/mms/buffer.h \
     ../../extras/package/win32/../../../modules/access/mms/mms.c \
     ../../extras/package/win32/../../../modules/access/mms/mms.h \
     ../../extras/package/win32/../../../modules/access/mms/mmsh.c \
     ../../extras/package/win32/../../../modules/access/mms/mmsh.h \
     ../../extras/package/win32/../../../modules/access/mms/mmstu.c \
     ../../extras/package/win32/../../../modules/access/mms/mmstu.h \
     ../../extras/package/win32/../../../modules/access/mtp.c \
     ../../extras/package/win32/../../../modules/access/oss.c \
     ../../extras/package/win32/../../../modules/access_output/dummy.c \
     ../../extras/package/win32/../../../modules/access_output/file.c \
     ../../extras/package/win32/../../../modules/access_output/http.c \
     ../../extras/package/win32/../../../modules/access_output/livehttp.c \
     ../../extras/package/win32/../../../modules/access_output/shout.c \
     ../../extras/package/win32/../../../modules/access_output/udp.c \
     ../../extras/package/win32/../../../modules/access/pulse.c \
     ../../extras/package/win32/../../../modules/access/rar/access.c \
     ../../extras/package/win32/../../../modules/access/rar/rar.c \
     ../../extras/package/win32/../../../modules/access/rar/rar.h \
     ../../extras/package/win32/../../../modules/access/rar/stream.c \
     ../../extras/package/win32/../../../modules/access/rdp.c \
     ../../extras/package/win32/../../../modules/access/rtp/input.c \
     ../../extras/package/win32/../../../modules/access/rtp/rtp.c \
     ../../extras/package/win32/../../../modules/access/rtp/rtp.h \
     ../../extras/package/win32/../../../modules/access/rtp/session.c \
     ../../extras/package/win32/../../../modules/access/rtsp/access.c \
     ../../extras/package/win32/../../../modules/access/rtsp/real_asmrp.c \
     ../../extras/package/win32/../../../modules/access/rtsp/real.c \
     ../../extras/package/win32/../../../modules/access/rtsp/real.h \
     ../../extras/package/win32/../../../modules/access/rtsp/real_rmff.c \
     ../../extras/package/win32/../../../modules/access/rtsp/real_rmff.h \
     ../../extras/package/win32/../../../modules/access/rtsp/real_sdpplin.c \
     ../../extras/package/win32/../../../modules/access/rtsp/real_sdpplin.h \
     ../../extras/package/win32/../../../modules/access/rtsp/rtsp.c \
     ../../extras/package/win32/../../../modules/access/rtsp/rtsp.h \
     ../../extras/package/win32/../../../modules/access/screen/mac.c \
     ../../extras/package/win32/../../../modules/access/screen/screen.c \
     ../../extras/package/win32/../../../modules/access/screen/screen.h \
     ../../extras/package/win32/../../../modules/access/screen/wayland.c \
     ../../extras/package/win32/../../../modules/access/screen/win32.c \
     ../../extras/package/win32/../../../modules/access/screen/xcb.c \
     ../../extras/package/win32/../../../modules/access/sdp.c \
     ../../extras/package/win32/../../../modules/access/sftp.c \
     ../../extras/package/win32/../../../modules/access/shm.c \
     ../../extras/package/win32/../../../modules/access/smb.c \
     ../../extras/package/win32/../../../modules/access/tcp.c \
     ../../extras/package/win32/../../../modules/access/timecode.c \
     ../../extras/package/win32/../../../modules/access/udp.c \
     ../../extras/package/win32/../../../modules/access/v4l2/controls.c \
     ../../extras/package/win32/../../../modules/access/v4l2/v4l2.c \
     ../../extras/package/win32/../../../modules/access/vcd/cdrom.c \
     ../../extras/package/win32/../../../modules/access/vcd/cdrom.h \
     ../../extras/package/win32/../../../modules/access/vcd/cdrom_internals.h \
     ../../extras/package/win32/../../../modules/access/vcd/vcd.c \
     ../../extras/package/win32/../../../modules/access/vcdx/access.c \
     ../../extras/package/win32/../../../modules/access/vcdx/info.c \
     ../../extras/package/win32/../../../modules/access/vcdx/info.h \
     ../../extras/package/win32/../../../modules/access/vcdx/vcd.c \
     ../../extras/package/win32/../../../modules/access/vcdx/vcd.h \
     ../../extras/package/win32/../../../modules/access/vcdx/vcdplayer.c \
     ../../extras/package/win32/../../../modules/access/vcdx/vcdplayer.h \
     ../../extras/package/win32/../../../modules/access/vdr.c \
     ../../extras/package/win32/../../../modules/access/vnc.c \
     ../../extras/package/win32/../../../modules/access/wasapi.c \
     ../../extras/package/win32/../../../modules/access/zip/zipstream.c \
     ../../extras/package/win32/../../../modules/arm_neon/chroma_yuv.c \
     ../../extras/package/win32/../../../modules/arm_neon/simple_channel_mixer.c \
     ../../extras/package/win32/../../../modules/arm_neon/volume.c \
     ../../extras/package/win32/../../../modules/arm_neon/yuv_rgb.c \
     ../../extras/package/win32/../../../modules/audio_filter/audiobargraph_a.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/dolby.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/headphone.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/mono.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/remap.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/simple.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/trivial.c \
     ../../extras/package/win32/../../../modules/audio_filter/chorus_flanger.c \
     ../../extras/package/win32/../../../modules/audio_filter/compressor.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/a52tofloat32.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/a52tospdif.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/dtstofloat32.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/dtstospdif.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/format.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/mpgatofixed32.c \
     ../../extras/package/win32/../../../modules/audio_filter/equalizer.c \
     ../../extras/package/win32/../../../modules/audio_filter/equalizer_presets.h \
     ../../extras/package/win32/../../../modules/audio_filter/gain.c \
     ../../extras/package/win32/../../../modules/audio_filter/karaoke.c \
     ../../extras/package/win32/../../../modules/audio_filter/normvol.c \
     ../../extras/package/win32/../../../modules/audio_filter/param_eq.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/bandlimited.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/bandlimited.h \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/speex.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/src.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/ugly.c \
     ../../extras/package/win32/../../../modules/audio_filter/scaletempo.c \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/allpass.cpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/allpass.hpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/comb.cpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/comb.hpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/denormals.h \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/revmodel.cpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/revmodel.hpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/spatializer.cpp \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/tuning.h \
     ../../extras/package/win32/../../../modules/audio_filter/stereo_widen.c \
     ../../extras/package/win32/../../../modules/audio_mixer/float.c \
     ../../extras/package/win32/../../../modules/audio_mixer/integer.c \
     ../../extras/package/win32/../../../modules/audio_output/adummy.c \
     ../../extras/package/win32/../../../modules/audio_output/alsa.c \
     ../../extras/package/win32/../../../modules/audio_output/amem.c \
     ../../extras/package/win32/../../../modules/audio_output/audioqueue.c \
     ../../extras/package/win32/../../../modules/audio_output/audiotrack.c \
     ../../extras/package/win32/../../../modules/audio_output/audiounit_ios.c \
     ../../extras/package/win32/../../../modules/audio_output/auhal.c \
     ../../extras/package/win32/../../../modules/audio_output/directsound.c \
     ../../extras/package/win32/../../../modules/audio_output/file.c \
     ../../extras/package/win32/../../../modules/audio_output/jack.c \
     ../../extras/package/win32/../../../modules/audio_output/kai.c \
     ../../extras/package/win32/../../../modules/audio_output/opensles_android.c \
     ../../extras/package/win32/../../../modules/audio_output/oss.c \
     ../../extras/package/win32/../../../modules/audio_output/pulse.c \
     ../../extras/package/win32/../../../modules/audio_output/sndio.c \
     ../../extras/package/win32/../../../modules/audio_output/volume.h \
     ../../extras/package/win32/../../../modules/audio_output/wasapi.c \
     ../../extras/package/win32/../../../modules/audio_output/waveout.c \
     ../../extras/package/win32/../../../modules/audio_output/windows_audio_common.h \
     ../../extras/package/win32/../../../modules/codec/a52.c \
     ../../extras/package/win32/../../../modules/codec/adpcm.c \
     ../../extras/package/win32/../../../modules/codec/aes3.c \
     ../../extras/package/win32/../../../modules/codec/araw.c \
     ../../extras/package/win32/../../../modules/codec/arib/aribsub.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/audio.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/avcodec.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/avcodec.h \
     ../../extras/package/win32/../../../modules/codec/avcodec/chroma.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/d3d11va.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/dxva2.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/encoder.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/fourcc.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/vaapi.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/vda.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/video.c \
     ../../extras/package/win32/../../../modules/codec/bpg.c \
     ../../extras/package/win32/../../../modules/codec/cc.c \
     ../../extras/package/win32/../../../modules/codec/cc.h \
     ../../extras/package/win32/../../../modules/codec/cdg.c \
     ../../extras/package/win32/../../../modules/codec/crystalhd.c \
     ../../extras/package/win32/../../../modules/codec/cvdsub.c \
     ../../extras/package/win32/../../../modules/codec/daala.c \
     ../../extras/package/win32/../../../modules/codec/ddummy.c \
     ../../extras/package/win32/../../../modules/codec/dmo/buffer.c \
     ../../extras/package/win32/../../../modules/codec/dmo/dmo.c \
     ../../extras/package/win32/../../../modules/codec/dmo/dmo.h \
     ../../extras/package/win32/../../../modules/codec/dts.c \
     ../../extras/package/win32/../../../modules/codec/dvbsub.c \
     ../../extras/package/win32/../../../modules/codec/edummy.c \
     ../../extras/package/win32/../../../modules/codec/faad.c \
     ../../extras/package/win32/../../../modules/codec/fdkaac.c \
     ../../extras/package/win32/../../../modules/codec/flac.c \
     ../../extras/package/win32/../../../modules/codec/fluidsynth.c \
     ../../extras/package/win32/../../../modules/codec/g711.c \
     ../../extras/package/win32/../../../modules/codec/gstdecode.c \
     ../../extras/package/win32/../../../modules/codec/jpeg.c \
     ../../extras/package/win32/../../../modules/codec/kate.c \
     ../../extras/package/win32/../../../modules/codec/libass.c \
     ../../extras/package/win32/../../../modules/codec/libmpeg2.c \
     ../../extras/package/win32/../../../modules/codec/lpcm.c \
     ../../extras/package/win32/../../../modules/codec/mft.c \
     ../../extras/package/win32/../../../modules/codec/mpeg_audio.c \
     ../../extras/package/win32/../../../modules/codec/mpg123.c \
     ../../extras/package/win32/../../../modules/codec/omxil/mediacodec.c \
     ../../extras/package/win32/../../../modules/codec/omxil/mediacodec_jni.c \
     ../../extras/package/win32/../../../modules/codec/omxil/mediacodec_ndk.c \
     ../../extras/package/win32/../../../modules/codec/omxil/mediacodec.h \
     ../../extras/package/win32/../../../modules/codec/omxil/omxil.c \
     ../../extras/package/win32/../../../modules/codec/omxil/omxil.h \
     ../../extras/package/win32/../../../modules/codec/omxil/omxil_utils.h \
     ../../extras/package/win32/../../../modules/codec/omxil/utils.c \
     ../../extras/package/win32/../../../modules/codec/omxil/vout.c \
     ../../extras/package/win32/../../../modules/codec/opus.c \
     ../../extras/package/win32/../../../modules/codec/png.c \
     ../../extras/package/win32/../../../modules/codec/qsv.c \
     ../../extras/package/win32/../../../modules/codec/quicktime.c \
     ../../extras/package/win32/../../../modules/codec/rawvideo.c \
     ../../extras/package/win32/../../../modules/codec/rtpvideo.c \
     ../../extras/package/win32/../../../modules/codec/schroedinger.c \
     ../../extras/package/win32/../../../modules/codec/sdl_image.c \
     ../../extras/package/win32/../../../modules/codec/shine.c \
     ../../extras/package/win32/../../../modules/codec/speex.c \
     ../../extras/package/win32/../../../modules/codec/spudec/parse.c \
     ../../extras/package/win32/../../../modules/codec/spudec/spudec.c \
     ../../extras/package/win32/../../../modules/codec/spudec/spudec.h \
     ../../extras/package/win32/../../../modules/codec/stl.c \
     ../../extras/package/win32/../../../modules/codec/subsdec.c \
     ../../extras/package/win32/../../../modules/codec/subsusf.c \
     ../../extras/package/win32/../../../modules/codec/substx3g.c \
     ../../extras/package/win32/../../../modules/codec/svcdsub.c \
     ../../extras/package/win32/../../../modules/codec/t140.c \
     ../../extras/package/win32/../../../modules/codec/telx.c \
     ../../extras/package/win32/../../../modules/codec/theora.c \
     ../../extras/package/win32/../../../modules/codec/substtml.c \
     ../../extras/package/win32/../../../modules/codec/twolame.c \
     ../../extras/package/win32/../../../modules/codec/uleaddvaudio.c \
     ../../extras/package/win32/../../../modules/codec/videotoolbox.m \
     ../../extras/package/win32/../../../modules/codec/vorbis.c \
     ../../extras/package/win32/../../../modules/codec/vpx.c \
     ../../extras/package/win32/../../../modules/codec/wmafixed/wma.c \
     ../../extras/package/win32/../../../modules/codec/x264.c \
     ../../extras/package/win32/../../../modules/codec/x265.c \
     ../../extras/package/win32/../../../modules/codec/xwd.c \
     ../../extras/package/win32/../../../modules/codec/zvbi.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_common.h \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_player.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_player.h \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_root.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_root.h \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_tracklist.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_tracklist.h \
     ../../extras/package/win32/../../../modules/control/dummy.c \
     ../../extras/package/win32/../../../modules/control/gestures.c \
     ../../extras/package/win32/../../../modules/control/globalhotkeys/win32.c \
     ../../extras/package/win32/../../../modules/control/globalhotkeys/xcb.c \
     ../../extras/package/win32/../../../modules/control/hotkeys.c \
     ../../extras/package/win32/../../../modules/control/intromsg.h \
     ../../extras/package/win32/../../../modules/control/lirc.c \
     ../../extras/package/win32/../../../modules/control/motion.c \
     ../../extras/package/win32/../../../modules/control/netsync.c \
     ../../extras/package/win32/../../../modules/control/ntservice.c \
     ../../extras/package/win32/../../../modules/control/oldrc.c \
     ../../extras/package/win32/../../../modules/control/unimotion.c \
     ../../extras/package/win32/../../../modules/control/unimotion.h \
     ../../extras/package/win32/../../../modules/demux/adaptative/adaptative.cpp \
     ../../extras/package/win32/../../../modules/demux/aiff.c \
     ../../extras/package/win32/../../../modules/demux/asf/asf.c \
     ../../extras/package/win32/../../../modules/demux/asf/libasf.c \
     ../../extras/package/win32/../../../modules/demux/asf/libasf.h \
     ../../extras/package/win32/../../../modules/demux/au.c \
     ../../extras/package/win32/../../../modules/demux/avformat/avformat.c \
     ../../extras/package/win32/../../../modules/demux/avformat/avformat.h \
     ../../extras/package/win32/../../../modules/demux/avformat/demux.c \
     ../../extras/package/win32/../../../modules/demux/avformat/mux.c \
     ../../extras/package/win32/../../../modules/demux/avi/avi.c \
     ../../extras/package/win32/../../../modules/demux/avi/libavi.c \
     ../../extras/package/win32/../../../modules/demux/avi/libavi.h \
     ../../extras/package/win32/../../../modules/demux/caf.c \
     ../../extras/package/win32/../../../modules/demux/cdg.c \
     ../../extras/package/win32/../../../modules/demux/demuxdump.c \
     ../../extras/package/win32/../../../modules/demux/dirac.c \
     ../../extras/package/win32/../../../modules/demux/flac.c \
     ../../extras/package/win32/../../../modules/demux/gme.c \
     ../../extras/package/win32/../../../modules/demux/image.c \
     ../../extras/package/win32/../../../modules/demux/mjpeg.c \
     ../../extras/package/win32/../../../modules/demux/mkv/chapter_command.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/chapter_command.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/chapters.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/chapters.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/demux.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/demux.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/Ebml_parser.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/Ebml_parser.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/matroska_segment.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/matroska_segment.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/matroska_segment_parse.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/mkv.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/mkv.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/stream_io_callback.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/stream_io_callback.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/util.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/util.hpp \
     ../../extras/package/win32/../../../modules/demux/mkv/virtual_segment.cpp \
     ../../extras/package/win32/../../../modules/demux/mkv/virtual_segment.hpp \
     ../../extras/package/win32/../../../modules/demux/mod.c \
     ../../extras/package/win32/../../../modules/demux/mp4/id3genres.h \
     ../../extras/package/win32/../../../modules/demux/mp4/libmp4.c \
     ../../extras/package/win32/../../../modules/demux/mp4/libmp4.h \
     ../../extras/package/win32/../../../modules/demux/mp4/mp4.c \
     ../../extras/package/win32/../../../modules/demux/mpc.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/es.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/h264.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/hevc.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/mpgv.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/ps.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/ps.h \
     ../../extras/package/win32/../../../modules/demux/mpeg/ts.c \
     ../../extras/package/win32/../../../modules/demux/nsc.c \
     ../../extras/package/win32/../../../modules/demux/nsv.c \
     ../../extras/package/win32/../../../modules/demux/nuv.c \
     ../../extras/package/win32/../../../modules/demux/ogg.c \
     ../../extras/package/win32/../../../modules/demux/playlist/asx.c \
     ../../extras/package/win32/../../../modules/demux/playlist/b4s.c \
     ../../extras/package/win32/../../../modules/demux/playlist/dvb.c \
     ../../extras/package/win32/../../../modules/demux/playlist/gvp.c \
     ../../extras/package/win32/../../../modules/demux/playlist/ifo.c \
     ../../extras/package/win32/../../../modules/demux/playlist/itml.c \
     ../../extras/package/win32/../../../modules/demux/playlist/itml.h \
     ../../extras/package/win32/../../../modules/demux/playlist/m3u.c \
     ../../extras/package/win32/../../../modules/demux/playlist/playlist.c \
     ../../extras/package/win32/../../../modules/demux/playlist/playlist.h \
     ../../extras/package/win32/../../../modules/demux/playlist/pls.c \
     ../../extras/package/win32/../../../modules/demux/playlist/podcast.c \
     ../../extras/package/win32/../../../modules/demux/playlist/qtl.c \
     ../../extras/package/win32/../../../modules/demux/playlist/sgimb.c \
     ../../extras/package/win32/../../../modules/demux/playlist/shoutcast.c \
     ../../extras/package/win32/../../../modules/demux/playlist/xspf.c \
     ../../extras/package/win32/../../../modules/demux/pva.c \
     ../../extras/package/win32/../../../modules/demux/rawaud.c \
     ../../extras/package/win32/../../../modules/demux/rawdv.c \
     ../../extras/package/win32/../../../modules/demux/rawvid.c \
     ../../extras/package/win32/../../../modules/demux/real.c \
     ../../extras/package/win32/../../../modules/demux/sid.cpp \
     ../../extras/package/win32/../../../modules/demux/smf.c \
     ../../extras/package/win32/../../../modules/demux/stl.c \
     ../../extras/package/win32/../../../modules/demux/subtitle.c \
     ../../extras/package/win32/../../../modules/demux/tta.c \
     ../../extras/package/win32/../../../modules/demux/ttml.c \
     ../../extras/package/win32/../../../modules/demux/ty.c \
     ../../extras/package/win32/../../../modules/demux/vc1.c \
     ../../extras/package/win32/../../../modules/demux/vobsub.c \
     ../../extras/package/win32/../../../modules/demux/voc.c \
     ../../extras/package/win32/../../../modules/demux/wav.c \
     ../../extras/package/win32/../../../modules/demux/xa.c \
     ../../extras/package/win32/../../../modules/demux/xiph_metadata.h \
     ../../extras/package/win32/../../../modules/demux/xiph_metadata.c \
     ../../extras/package/win32/../../../modules/gui/macosx/about.h \
     ../../extras/package/win32/../../../modules/gui/macosx/about.m \
     ../../extras/package/win32/../../../modules/gui/macosx/AddonsWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/AddonsWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/AppleRemote.h \
     ../../extras/package/win32/../../../modules/gui/macosx/AppleRemote.m \
     ../../extras/package/win32/../../../modules/gui/macosx/applescript.h \
     ../../extras/package/win32/../../../modules/gui/macosx/applescript.m \
     ../../extras/package/win32/../../../modules/gui/macosx/AudioEffects.h \
     ../../extras/package/win32/../../../modules/gui/macosx/AudioEffects.m \
     ../../extras/package/win32/../../../modules/gui/macosx/bookmarks.h \
     ../../extras/package/win32/../../../modules/gui/macosx/bookmarks.m \
     ../../extras/package/win32/../../../modules/gui/macosx/BWQuincyUI.h \
     ../../extras/package/win32/../../../modules/gui/macosx/BWQuincyUI.m \
     ../../extras/package/win32/../../../modules/gui/macosx/ControlsBar.h \
     ../../extras/package/win32/../../../modules/gui/macosx/ControlsBar.m \
     ../../extras/package/win32/../../../modules/gui/macosx/ConvertAndSave.h \
     ../../extras/package/win32/../../../modules/gui/macosx/ConvertAndSave.m \
     ../../extras/package/win32/../../../modules/gui/macosx/coredialogs.h \
     ../../extras/package/win32/../../../modules/gui/macosx/coredialogs.m \
     ../../extras/package/win32/../../../modules/gui/macosx/CoreInteraction.h \
     ../../extras/package/win32/../../../modules/gui/macosx/CoreInteraction.m \
     ../../extras/package/win32/../../../modules/gui/macosx_dialog_provider/dialogProvider.m \
     ../../extras/package/win32/../../../modules/gui/macosx_dialog_provider/VLCLoginPanel.h \
     ../../extras/package/win32/../../../modules/gui/macosx_dialog_provider/VLCLoginPanel.m \
     ../../extras/package/win32/../../../modules/gui/macosx_dialog_provider/VLCProgressPanel.h \
     ../../extras/package/win32/../../../modules/gui/macosx_dialog_provider/VLCProgressPanel.m \
     ../../extras/package/win32/../../../modules/gui/macosx/ExtensionsDialogProvider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/ExtensionsDialogProvider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/ExtensionsManager.h \
     ../../extras/package/win32/../../../modules/gui/macosx/ExtensionsManager.m \
     ../../extras/package/win32/../../../modules/gui/macosx/eyetv.h \
     ../../extras/package/win32/../../../modules/gui/macosx/eyetv.m \
     ../../extras/package/win32/../../../modules/gui/macosx/fspanel.h \
     ../../extras/package/win32/../../../modules/gui/macosx/fspanel.m \
     ../../extras/package/win32/../../../modules/gui/macosx/helpers.h \
     ../../extras/package/win32/../../../modules/gui/macosx/intf.h \
     ../../extras/package/win32/../../../modules/gui/macosx/intf.m \
     ../../extras/package/win32/../../../modules/gui/macosx/intf-prefs.h \
     ../../extras/package/win32/../../../modules/gui/macosx/intf-prefs.m \
     ../../extras/package/win32/../../../modules/gui/macosx/macosx.m \
     ../../extras/package/win32/../../../modules/gui/macosx/MainMenu.h \
     ../../extras/package/win32/../../../modules/gui/macosx/MainMenu.m \
     ../../extras/package/win32/../../../modules/gui/macosx/MainWindow.h \
     ../../extras/package/win32/../../../modules/gui/macosx/MainWindow.m \
     ../../extras/package/win32/../../../modules/gui/macosx/MainWindowTitle.h \
     ../../extras/package/win32/../../../modules/gui/macosx/MainWindowTitle.m \
     ../../extras/package/win32/../../../modules/gui/macosx/misc.h \
     ../../extras/package/win32/../../../modules/gui/macosx/misc.m \
     ../../extras/package/win32/../../../modules/gui/macosx/open.h \
     ../../extras/package/win32/../../../modules/gui/macosx/open.m \
     ../../extras/package/win32/../../../modules/gui/macosx/output.h \
     ../../extras/package/win32/../../../modules/gui/macosx/output.m \
     ../../extras/package/win32/../../../modules/gui/macosx/playlist.h \
     ../../extras/package/win32/../../../modules/gui/macosx/playlist.m \
     ../../extras/package/win32/../../../modules/gui/macosx/playlistinfo.h \
     ../../extras/package/win32/../../../modules/gui/macosx/playlistinfo.m \
     ../../extras/package/win32/../../../modules/gui/macosx/playlistview.h \
     ../../extras/package/win32/../../../modules/gui/macosx/playlistview.m \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs.h \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs.m \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs_widgets.h \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs_widgets.m \
     ../../extras/package/win32/../../../modules/gui/macosx/ResumeDialogController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/ResumeDialogController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/simple_prefs.h \
     ../../extras/package/win32/../../../modules/gui/macosx/simple_prefs.m \
     ../../extras/package/win32/../../../modules/gui/macosx/StringUtility.h \
     ../../extras/package/win32/../../../modules/gui/macosx/StringUtility.m \
     ../../extras/package/win32/../../../modules/gui/macosx/TrackSynchronization.h \
     ../../extras/package/win32/../../../modules/gui/macosx/TrackSynchronization.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VideoEffects.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VideoEffects.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VideoView.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VideoView.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTimeSelectionPanelController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTimeSelectionPanelController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVoutWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVoutWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/Windows.h \
     ../../extras/package/win32/../../../modules/gui/macosx/Windows.m \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/intf.h \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/intf.m \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/macosx.c \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.h \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.m \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/misc.h \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/misc.m \
     ../../extras/package/win32/../../../modules/gui/ncurses.c \
     ../../extras/package/win32/../../../modules/gui/qt4/components/complete_preferences.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/complete_preferences.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/controller.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/controller.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/controller_widget.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/controller_widget.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/extended_panels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/extended_panels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/epg/EPGWidget.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/info_panels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/info_panels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/info_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/info_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/interface_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/interface_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/open_panels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/open_panels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/playlist.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/playlist.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/playlist_item.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/playlist_item.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/playlist_model.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/playlist_model.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/selector.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/selector.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/sorting.h \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/standardpanel.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/playlist/standardpanel.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/preferences_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/preferences_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/simple_preferences.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/simple_preferences.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/sout/profile_selector.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/components/sout/sout_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/bookmarks.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/bookmarks.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/convert.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/convert.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/errors.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/errors.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/extended.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/extended.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/external.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/external.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/firstrun.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/gototime.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/gototime.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/help.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/help.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/mediainfo.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/mediainfo.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/messages.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/messages.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/open.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/open.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/openurl.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/openurl.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/playlist.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/playlist.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/plugins.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/podcast_configuration.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/podcast_configuration.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/preferences.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/preferences.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs_provider.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs_provider.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/sout.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/sout.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/toolbar.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/toolbar.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/vlm.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/dialogs/vlm.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/input_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/input_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/main_interface.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/main_interface.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/menus.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/menus.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/qt4.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/qt4.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/recents.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/recents.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/customwidgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/customwidgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/input_slider.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/input_slider.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/qvlcapp.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/qvlcframe.hpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/registry.cpp \
     ../../extras/package/win32/../../../modules/gui/qt4/util/registry.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/async_queue.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/async_queue.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_add_item.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_add_item.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_audio.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_audio.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_change_skin.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_change_skin.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dialogs.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dummy.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dvd.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dvd.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_fullscreen.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_fullscreen.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_generic.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_input.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_input.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_layout.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_layout.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_minimize.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_minimize.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_muxer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_muxer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_on_top.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_on_top.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playlist.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playlist.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playtree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playtree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_quit.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_quit.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_resize.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_resize.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_show_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_snapshot.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_snapshot.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_vars.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_vars.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_button.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_button.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_checkbox.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_checkbox.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_flat.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_generic.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_generic.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_image.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_image.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_list.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_list.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_move.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_move.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_radialslider.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_radialslider.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_resize.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_resize.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_slider.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_slider.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_text.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_text.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_tree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_tree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_video.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_video.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_enter.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_focus.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_generic.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_input.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_input.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_key.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_key.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_leave.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_menu.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_motion.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_mouse.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_mouse.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_refresh.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_scroll.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_scroll.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_special.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_special.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_dragdrop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_dragdrop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_graphics.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_loop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_timer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/macosx/macosx_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/builder.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/builder_data.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/builder.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/expr_evaluator.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/expr_evaluator.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/interpreter.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/interpreter.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/skin_parser.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/skin_parser.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/xmlparser.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/xmlparser.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anchor.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anchor.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anim_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anim_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/bitmap_font.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/bitmap_font.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/dialogs.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/dialogs.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/file_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/file_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_font.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_font.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_font.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_layout.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_layout.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ini_file.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ini_file.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/logger.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/logger.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/scaled_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/scaled_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/skin_common.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/skin_main.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_loader.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_loader.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_repository.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_repository.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/top_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/top_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/var_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/var_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vlcproc.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vlcproc.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vout_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vout_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/window_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/window_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/bezier.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/bezier.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/fsm.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/fsm.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/observer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/pointer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/position.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/position.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/ustring.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/ustring.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_bool.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_bool.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/variable.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_list.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_list.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_percent.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_percent.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_text.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_text.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_tree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_tree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/equalizer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/equalizer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/playtree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/playtree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/time.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/time.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/volume.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/volume.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_dragdrop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_dragdrop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_graphics.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_loop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_timer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_display.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_display.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_dragdrop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_dragdrop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_graphics.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_loop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_timer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_window.hpp \
     ../../extras/package/win32/../../../modules/hw/mmal/codec.c \
     ../../extras/package/win32/../../../modules/hw/mmal/vout.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/adjust.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/avcodec.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/chroma.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/deinterlace.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/display.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/sharpen.c \
     ../../extras/package/win32/../../../modules/lua/demux.c \
     ../../extras/package/win32/../../../modules/lua/intf.c \
     ../../extras/package/win32/../../../modules/lua/libs/configuration.c \
     ../../extras/package/win32/../../../modules/lua/libs.h \
     ../../extras/package/win32/../../../modules/lua/libs/httpd.c \
     ../../extras/package/win32/../../../modules/lua/libs/input.c \
     ../../extras/package/win32/../../../modules/lua/libs/input.h \
     ../../extras/package/win32/../../../modules/lua/libs/messages.c \
     ../../extras/package/win32/../../../modules/lua/libs/misc.c \
     ../../extras/package/win32/../../../modules/lua/libs/misc.h \
     ../../extras/package/win32/../../../modules/lua/libs/net.c \
     ../../extras/package/win32/../../../modules/lua/libs/objects.c \
     ../../extras/package/win32/../../../modules/lua/libs/objects.h \
     ../../extras/package/win32/../../../modules/lua/libs/osd.c \
     ../../extras/package/win32/../../../modules/lua/libs/playlist.c \
     ../../extras/package/win32/../../../modules/lua/libs/sd.c \
     ../../extras/package/win32/../../../modules/lua/libs/stream.c \
     ../../extras/package/win32/../../../modules/lua/libs/strings.c \
     ../../extras/package/win32/../../../modules/lua/libs/variables.c \
     ../../extras/package/win32/../../../modules/lua/libs/variables.h \
     ../../extras/package/win32/../../../modules/lua/libs/video.c \
     ../../extras/package/win32/../../../modules/lua/libs/vlm.c \
     ../../extras/package/win32/../../../modules/lua/libs/volume.c \
     ../../extras/package/win32/../../../modules/lua/meta.c \
     ../../extras/package/win32/../../../modules/lua/vlc.c \
     ../../extras/package/win32/../../../modules/lua/vlc.h \
     ../../extras/package/win32/../../../modules/meta_engine/folder.c \
     ../../extras/package/win32/../../../modules/meta_engine/taglib.cpp \
     ../../extras/package/win32/../../../modules/misc/audioscrobbler.c \
     ../../extras/package/win32/../../../modules/misc/gnutls.c \
     ../../extras/package/win32/../../../modules/misc/inhibit/dbus.c \
     ../../extras/package/win32/../../../modules/misc/inhibit/xdg.c \
     ../../extras/package/win32/../../../modules/misc/logger.c \
     ../../extras/package/win32/../../../modules/misc/playlist/export.c \
     ../../extras/package/win32/../../../modules/misc/playlist/html.c \
     ../../extras/package/win32/../../../modules/misc/playlist/m3u.c \
     ../../extras/package/win32/../../../modules/misc/playlist/xspf.c \
     ../../extras/package/win32/../../../modules/misc/rtsp.c \
     ../../extras/package/win32/../../../modules/misc/securetransport.c \
     ../../extras/package/win32/../../../modules/misc/stats.c \
     ../../extras/package/win32/../../../modules/misc/xml/libxml.c \
     ../../extras/package/win32/../../../modules/mux/asf.c \
     ../../extras/package/win32/../../../modules/mux/avi.c \
     ../../extras/package/win32/../../../modules/mux/dummy.c \
     ../../extras/package/win32/../../../modules/mux/mp4.c \
     ../../extras/package/win32/../../../modules/mux/mpeg/bits.h \
     ../../extras/package/win32/../../../modules/mux/mpeg/csa.c \
     ../../extras/package/win32/../../../modules/mux/mpeg/csa.h \
     ../../extras/package/win32/../../../modules/mux/mpeg/pes.c \
     ../../extras/package/win32/../../../modules/mux/mpeg/pes.h \
     ../../extras/package/win32/../../../modules/mux/mpeg/ps.c \
     ../../extras/package/win32/../../../modules/mux/mpeg/ts.c \
     ../../extras/package/win32/../../../modules/mux/mpjpeg.c \
     ../../extras/package/win32/../../../modules/mux/ogg.c \
     ../../extras/package/win32/../../../modules/mux/wav.c \
     ../../extras/package/win32/../../../modules/notify/growl.m \
     ../../extras/package/win32/../../../modules/notify/notify.c \
     ../../extras/package/win32/../../../modules/packetizer/avparser.h \
     ../../extras/package/win32/../../../modules/packetizer/copy.c \
     ../../extras/package/win32/../../../modules/packetizer/dirac.c \
     ../../extras/package/win32/../../../modules/packetizer/flac.c \
     ../../extras/package/win32/../../../modules/packetizer/h264.c \
     ../../extras/package/win32/../../../modules/packetizer/hevc.c \
     ../../extras/package/win32/../../../modules/packetizer/mlp.c \
     ../../extras/package/win32/../../../modules/packetizer/mpeg4audio.c \
     ../../extras/package/win32/../../../modules/packetizer/mpeg4video.c \
     ../../extras/package/win32/../../../modules/packetizer/mpegvideo.c \
     ../../extras/package/win32/../../../modules/packetizer/vc1.c \
     ../../extras/package/win32/../../../modules/services_discovery/bonjour.c \
     ../../extras/package/win32/../../../modules/services_discovery/mediadirs.c \
     ../../extras/package/win32/../../../modules/services_discovery/mtp.c \
     ../../extras/package/win32/../../../modules/services_discovery/os2drive.c \
     ../../extras/package/win32/../../../modules/services_discovery/podcast.c \
     ../../extras/package/win32/../../../modules/services_discovery/pulse.c \
     ../../extras/package/win32/../../../modules/services_discovery/sap.c \
     ../../extras/package/win32/../../../modules/services_discovery/udev.c \
     ../../extras/package/win32/../../../modules/services_discovery/upnp.cpp \
     ../../extras/package/win32/../../../modules/services_discovery/windrive.c \
     ../../extras/package/win32/../../../modules/services_discovery/xcb_apps.c \
     ../../extras/package/win32/../../../modules/stream_filter/aribcam.c \
     ../../extras/package/win32/../../../modules/stream_filter/cache_block.c \
     ../../extras/package/win32/../../../modules/stream_filter/cache_read.c \
     ../../extras/package/win32/../../../modules/stream_filter/decomp.c \
     ../../extras/package/win32/../../../modules/stream_filter/hds/hds.c \
     ../../extras/package/win32/../../../modules/stream_filter/record.c \
     ../../extras/package/win32/../../../modules/stream_filter/smooth/smooth.c \
     ../../extras/package/win32/../../../modules/stream_out/autodel.c \
     ../../extras/package/win32/../../../modules/stream_out/bridge.c \
     ../../extras/package/win32/../../../modules/stream_out/cycle.c \
     ../../extras/package/win32/../../../modules/stream_out/delay.c \
     ../../extras/package/win32/../../../modules/stream_out/description.c \
     ../../extras/package/win32/../../../modules/stream_out/display.c \
     ../../extras/package/win32/../../../modules/stream_out/dummy.c \
     ../../extras/package/win32/../../../modules/stream_out/duplicate.c \
     ../../extras/package/win32/../../../modules/stream_out/es.c \
     ../../extras/package/win32/../../../modules/stream_out/gather.c \
     ../../extras/package/win32/../../../modules/stream_out/mosaic_bridge.c \
     ../../extras/package/win32/../../../modules/stream_out/raop.c \
     ../../extras/package/win32/../../../modules/stream_out/record.c \
     ../../extras/package/win32/../../../modules/stream_out/rtcp.c \
     ../../extras/package/win32/../../../modules/stream_out/rtp.c \
     ../../extras/package/win32/../../../modules/stream_out/rtpfmt.c \
     ../../extras/package/win32/../../../modules/stream_out/rtp.h \
     ../../extras/package/win32/../../../modules/stream_out/rtsp.c \
     ../../extras/package/win32/../../../modules/stream_out/setid.c \
     ../../extras/package/win32/../../../modules/stream_out/smem.c \
     ../../extras/package/win32/../../../modules/stream_out/stats.c \
     ../../extras/package/win32/../../../modules/stream_out/standard.c \
     ../../extras/package/win32/../../../modules/stream_out/transcode/transcode.c \
     ../../extras/package/win32/../../../modules/text_renderer/freetype.c \
     ../../extras/package/win32/../../../modules/text_renderer/nsspeechsynthesizer.m \
     ../../extras/package/win32/../../../modules/text_renderer/quartztext.c \
     ../../extras/package/win32/../../../modules/text_renderer/svg.c \
     ../../extras/package/win32/../../../modules/text_renderer/tdummy.c \
     ../../extras/package/win32/../../../modules/text_renderer/win32text.c \
     ../../extras/package/win32/../../../modules/video_chroma/chain.c \
     ../../extras/package/win32/../../../modules/video_chroma/cvpx_i420.c \
     ../../extras/package/win32/../../../modules/video_chroma/d3d11_surface.c \
     ../../extras/package/win32/../../../modules/video_chroma/dxa9.c \
     ../../extras/package/win32/../../../modules/video_chroma/grey_yuv.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb16.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb8.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb_c.h \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb.h \
     ../../extras/package/win32/../../../modules/video_chroma/i420_yuy2.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_yuy2.h \
     ../../extras/package/win32/../../../modules/video_chroma/i422_i420.c \
     ../../extras/package/win32/../../../modules/video_chroma/i422_yuy2.c \
     ../../extras/package/win32/../../../modules/video_chroma/i422_yuy2.h \
     ../../extras/package/win32/../../../modules/video_chroma/omxdl.c \
     ../../extras/package/win32/../../../modules/video_chroma/rv32.c \
     ../../extras/package/win32/../../../modules/video_chroma/swscale.c \
     ../../extras/package/win32/../../../modules/video_chroma/yuy2_i420.c \
     ../../extras/package/win32/../../../modules/video_chroma/yuy2_i422.c \
     ../../extras/package/win32/../../../modules/video_filter/adjust.c \
     ../../extras/package/win32/../../../modules/video_filter/alphamask.c \
     ../../extras/package/win32/../../../modules/video_filter/anaglyph.c \
     ../../extras/package/win32/../../../modules/video_filter/antiflicker.c \
     ../../extras/package/win32/../../../modules/video_filter/audiobargraph_v.c \
     ../../extras/package/win32/../../../modules/video_filter/ball.c \
     ../../extras/package/win32/../../../modules/video_filter/blendbench.c \
     ../../extras/package/win32/../../../modules/video_filter/blend.cpp \
     ../../extras/package/win32/../../../modules/video_filter/bluescreen.c \
     ../../extras/package/win32/../../../modules/video_filter/canvas.c \
     ../../extras/package/win32/../../../modules/video_filter/colorthres.c \
     ../../extras/package/win32/../../../modules/video_filter/croppadd.c \
     ../../extras/package/win32/../../../modules/video_filter/deinterlace/algo_phosphor.h \
     ../../extras/package/win32/../../../modules/video_filter/deinterlace/deinterlace.c \
     ../../extras/package/win32/../../../modules/video_filter/deinterlace/deinterlace.h \
     ../../extras/package/win32/../../../modules/video_filter/dynamicoverlay/dynamicoverlay_buffer.c \
     ../../extras/package/win32/../../../modules/video_filter/dynamicoverlay/dynamicoverlay.c \
     ../../extras/package/win32/../../../modules/video_filter/dynamicoverlay/dynamicoverlay_commands.c \
     ../../extras/package/win32/../../../modules/video_filter/dynamicoverlay/dynamicoverlay.h \
     ../../extras/package/win32/../../../modules/video_filter/dynamicoverlay/dynamicoverlay_list.c \
     ../../extras/package/win32/../../../modules/video_filter/dynamicoverlay/dynamicoverlay_queue.c \
     ../../extras/package/win32/../../../modules/video_filter/erase.c \
     ../../extras/package/win32/../../../modules/video_filter/extract.c \
     ../../extras/package/win32/../../../modules/video_filter/filter_event_info.h \
     ../../extras/package/win32/../../../modules/video_filter/filter_picture.h \
     ../../extras/package/win32/../../../modules/video_filter/fps.c \
     ../../extras/package/win32/../../../modules/video_filter/freeze.c \
     ../../extras/package/win32/../../../modules/video_filter/gaussianblur.c \
     ../../extras/package/win32/../../../modules/video_filter/gradfun.c \
     ../../extras/package/win32/../../../modules/video_filter/gradient.c \
     ../../extras/package/win32/../../../modules/video_filter/grain.c \
     ../../extras/package/win32/../../../modules/video_filter/hqdn3d.c \
     ../../extras/package/win32/../../../modules/video_filter/invert.c \
     ../../extras/package/win32/../../../modules/video_filter/logo.c \
     ../../extras/package/win32/../../../modules/video_filter/magnify.c \
     ../../extras/package/win32/../../../modules/video_filter/marq.c \
     ../../extras/package/win32/../../../modules/video_filter/mirror.c \
     ../../extras/package/win32/../../../modules/video_filter/mosaic.c \
     ../../extras/package/win32/../../../modules/video_filter/mosaic.h \
     ../../extras/package/win32/../../../modules/video_filter/motionblur.c \
     ../../extras/package/win32/../../../modules/video_filter/motiondetect.c \
     ../../extras/package/win32/../../../modules/video_filter/oldmovie.c \
     ../../extras/package/win32/../../../modules/video_filter/opencv_example.cpp \
     ../../extras/package/win32/../../../modules/video_filter/opencv_wrapper.c \
     ../../extras/package/win32/../../../modules/video_filter/posterize.c \
     ../../extras/package/win32/../../../modules/video_filter/postproc.c \
     ../../extras/package/win32/../../../modules/video_filter/psychedelic.c \
     ../../extras/package/win32/../../../modules/video_filter/puzzle.c \
     ../../extras/package/win32/../../../modules/video_filter/remoteosd.c \
     ../../extras/package/win32/../../../modules/video_filter/remoteosd_rfbproto.h \
     ../../extras/package/win32/../../../modules/video_filter/ripple.c \
     ../../extras/package/win32/../../../modules/video_filter/rotate.c \
     ../../extras/package/win32/../../../modules/video_filter/rss.c \
     ../../extras/package/win32/../../../modules/video_filter/scale.c \
     ../../extras/package/win32/../../../modules/video_filter/scene.c \
     ../../extras/package/win32/../../../modules/video_filter/sepia.c \
     ../../extras/package/win32/../../../modules/video_filter/sharpen.c \
     ../../extras/package/win32/../../../modules/video_filter/subsdelay.c \
     ../../extras/package/win32/../../../modules/video_filter/transform.c \
     ../../extras/package/win32/../../../modules/video_filter/vhs.c \
     ../../extras/package/win32/../../../modules/video_filter/wave.c \
     ../../extras/package/win32/../../../modules/video_filter/yuvp.c \
     ../../extras/package/win32/../../../modules/video_output/aa.c \
     ../../extras/package/win32/../../../modules/video_output/android/android_window.c \
     ../../extras/package/win32/../../../modules/video_output/android/nativewindow.c \
     ../../extras/package/win32/../../../modules/video_output/caca.c \
     ../../extras/package/win32/../../../modules/video_output/caopengllayer.m \
     ../../extras/package/win32/../../../modules/video_output/decklink.cpp \
     ../../extras/package/win32/../../../modules/video_output/directfb.c \
     ../../extras/package/win32/../../../modules/video_output/drawable.c \
     ../../extras/package/win32/../../../modules/video_output/egl.c \
     ../../extras/package/win32/../../../modules/video_output/fb.c \
     ../../extras/package/win32/../../../modules/video_output/gl.c \
     ../../extras/package/win32/../../../modules/video_output/glx.c \
     ../../extras/package/win32/../../../modules/video_output/ios2.m \
     ../../extras/package/win32/../../../modules/video_output/kva.c \
     ../../extras/package/win32/../../../modules/video_output/macosx.m \
     ../../extras/package/win32/../../../modules/video_output/msw/direct2d.c \
     ../../extras/package/win32/../../../modules/video_output/msw/direct3d9.c \
     ../../extras/package/win32/../../../modules/video_output/msw/direct3d11.c \
     ../../extras/package/win32/../../../modules/video_output/msw/directdraw.c \
     ../../extras/package/win32/../../../modules/video_output/msw/events.c \
     ../../extras/package/win32/../../../modules/video_output/msw/glwin32.c \
     ../../extras/package/win32/../../../modules/video_output/msw/wingdi.c \
     ../../extras/package/win32/../../../modules/video_output/sdl.c \
     ../../extras/package/win32/../../../modules/video_output/vdummy.c \
     ../../extras/package/win32/../../../modules/video_output/vmem.c \
     ../../extras/package/win32/../../../modules/video_output/wayland/shell_surface.c \
     ../../extras/package/win32/../../../modules/video_output/wayland/shm.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/glx.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/window.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/x11.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/xvideo.c \
     ../../extras/package/win32/../../../modules/video_output/yuv.c \
     ../../extras/package/win32/../../../modules/video_splitter/clone.c \
     ../../extras/package/win32/../../../modules/video_splitter/panoramix.c \
     ../../extras/package/win32/../../../modules/video_splitter/wall.c \
     ../../extras/package/win32/../../../modules/visualization/goom.c \
     ../../extras/package/win32/../../../modules/visualization/projectm.cpp \
     ../../extras/package/win32/../../../modules/visualization/visual/effects.c \
     ../../extras/package/win32/../../../modules/visualization/visual/fft.c \
     ../../extras/package/win32/../../../modules/visualization/visual/fft.h \
     ../../extras/package/win32/../../../modules/visualization/visual/visual.c \
     ../../extras/package/win32/../../../modules/visualization/visual/visual.h \
     ../../extras/package/win32/../../../modules/visualization/vsxu.cpp \
     ../../extras/package/win32/../../../share/lua/http/dialogs/batch_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/browse_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/create_stream.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/equalizer_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/error_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/mosaic_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/offset_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/stream_config_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/stream_window.html \
     ../../extras/package/win32/../../../share/lua/http/index.html \
     ../../extras/package/win32/../../../share/lua/http/mobile_browse.html \
     ../../extras/package/win32/../../../share/lua/http/mobile_equalizer.html \
     ../../extras/package/win32/../../../share/lua/http/mobile.html \
     ../../extras/package/win32/../../../share/lua/http/mobile_view.html

CATALOGS =  ach.gmo af.gmo am.gmo an.gmo ar.gmo ast.gmo az.gmo be.gmo bg.gmo bn_IN.gmo bn.gmo br.gmo bs.gmo ca.gmo cgg.gmo ckb.gmo co.gmo cs.gmo cy.gmo da.gmo de.gmo el.gmo en_GB.gmo es.gmo et.gmo eu.gmo fa.gmo ff.gmo fi.gmo fr.gmo fur.gmo ga.gmo gd.gmo gl.gmo gu.gmo he.gmo hi.gmo hr.gmo hu.gmo hy.gmo ia.gmo id.gmo is.gmo it.gmo ja.gmo ka.gmo kk.gmo km.gmo kn.gmo ko.gmo ky.gmo lg.gmo lt.gmo lv.gmo mk.gmo ml.gmo mn.gmo mr.gmo ms.gmo my.gmo nb.gmo ne.gmo nl.gmo nn.gmo oc.gmo or.gmo pa.gmo pl.gmo ps.gmo pt_BR.gmo pt_PT.gmo ro.gmo ru.gmo si.gmo sk.gmo sl.gmo sq.gmo sr.gmo sv.gmo ta.gmo te.gmo tet.gmo th.gmo tl.gmo tr.gmo uk.gmo uz.gmo vi.gmo wa.gmo zh_CN.gmo zh_TW.gmo zu.gmo

POFILESDEPS_ = $(srcdir)/$(DOMAIN).pot
POFILESDEPS_yes = $(POFILESDEPS_)
POFILESDEPS_no =
POFILESDEPS = $(POFILESDEPS_$(PO_DEPENDS_ON_POT))

DISTFILESDEPS_ = update-po
DISTFILESDEPS_yes = $(DISTFILESDEPS_)
DISTFILESDEPS_no =
DISTFILESDEPS = $(DISTFILESDEPS_$(DIST_DEPENDS_ON_UPDATE_PO))

# Makevars gets inserted here. (Don't remove this line!)
# Makefile variables for PO directory in any package using GNU gettext.

VPATH += ../modules/gui ../modules/gui/qt4 ../modules/gui/qt4/ui

# Usually the message domain is the same as the package name.
DOMAIN = $(PACKAGE)

# These two variables depend on the location of this directory.
subdir = po
top_builddir = ..

# These options get passed to xgettext.
XGETTEXT_OPTIONS = --directory=.. --keyword=_ --keyword=N_ --keyword=_NS --keyword=_ANS --keyword=qtr --keyword=Q_ --language=C++ --keyword=vlc_ngettext:1,2 --keyword=vlc_pgettext:1c,2 --add-comments=xgettext: --from-code=UTF-8

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  Set this to the copyright holder of the surrounding
# package.  (Note that the msgstr strings, extracted from the package's
# sources, belong to the copyright holder of the package.)  Translators are
# expected to transfer the copyright for their translations to this person
# or entity, or to disclaim their copyright.  The empty string stands for
# the public domain; in this case the translators are expected to disclaim
# their copyright.
COPYRIGHT_HOLDER = VideoLAN

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS = vlc-devel@videolan.org

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

.SUFFIXES:
.SUFFIXES: .po .gmo .mo .sed .sin .nop .po-create .po-update

.po.mo:
	@echo "$(MSGFMT) -c -o $@ $<"; \
	$(MSGFMT) -c -o t-$@ $< && mv t-$@ $@

.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o $${lang}.gmo $${lang}.po"; \
	cd $(srcdir) && rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o t-$${lang}.gmo $${lang}.po && mv t-$${lang}.gmo $${lang}.gmo

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all: all-yes

all-yes: stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
CHECK_MACRO_VERSION = \
	test "$(GETTEXT_MACRO_VERSION)" = "0.19" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.19" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, stamp-po is a nop (i.e. a phony target).

# stamp-po is a timestamp denoting the last time at which the CATALOGS have
# been loosely updated. Its purpose is that when a developer or translator
# checks out the package via CVS, and the $(DOMAIN).pot file is not in CVS,
# "make" will update the $(DOMAIN).pot and the $(CATALOGS), but subsequent
# invocations of "make" will do nothing. This timestamp would not be necessary
# if updating the $(CATALOGS) would always touch them; however, the rule for
# $(POFILES) has been designed to not touch files that don't need to be
# changed.
stamp-po: $(srcdir)/$(DOMAIN).pot
	@$(CHECK_MACRO_VERSION)
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch stamp-po" && \
	  echo timestamp > stamp-poT && \
	  mv stamp-poT stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
# The determination of whether the package xyz is a GNU one is based on the
# heuristic whether some file in the top level directory mentions "GNU xyz".
# If GNU 'find' is available, we avoid grepping through monster files.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in remove-potcdate.sed
	package_gnu="$(PACKAGE_GNU)"; \
	test -n "$$package_gnu" || { \
	  if { if (LC_ALL=C find --version) 2>/dev/null | grep GNU >/dev/null; then \
		 LC_ALL=C find -L $(top_srcdir) -maxdepth 1 -type f \
			       -size -10000000c -exec grep 'GNU vlc' \
			       /dev/null '{}' ';' 2>/dev/null; \
	       else \
		 LC_ALL=C grep 'GNU vlc' $(top_srcdir)/* 2>/dev/null; \
	       fi; \
	     } | grep -v 'libtool:' >/dev/null; then \
	     package_gnu=yes; \
	   else \
	     package_gnu=no; \
	   fi; \
	}; \
	if test "$$package_gnu" = "yes"; then \
	  package_prefix='GNU '; \
	else \
	  package_prefix=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_prefix}vlc" \
	      --package-version='3.0.0-git' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    sed -f remove-potcdate.sed < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    sed -f remove-potcdate.sed < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(POFILESDEPS)
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test -f $(srcdir)/$(DOMAIN).pot || $(MAKE) $(srcdir)/$(DOMAIN).pot; \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) \
	    && { case `$(MSGMERGE_UPDATE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	           '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) $${lang}.po $(DOMAIN).pot;; \
	           *) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot;; \
	         esac; \
	       }; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

mostlyclean:
	rm -f remove-potcdate.sed
	rm -f stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES *.mo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	test -z "$(DISTFILESDEPS)" || $(MAKE) $(DISTFILESDEPS)
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: stamp-po $(DISTFILES)
	dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	       '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       *) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	     esac; \
	   }; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile $(GMOFILES)
	@:

# Recreate Makefile by invoking config.status. Explicitly invoke the shell,
# because execution permission bits may not work on the current file system.
# Use /bin/bash, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/bash ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
