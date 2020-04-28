// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

/* This file is auto generated                               */
/* Do not edit it manually                                   */

#include "Affinity/CppPrivate.h"
#include "Affinity/CppStructs.h" // IWYU pragma: associated

namespace AffinityReader::CppModel {

AF_DEFINE(BaseColor);
AF_DEFINE(BaseAdjustment);
AF_DEFINE(BaseFill);
AF_DEFINE(BaseLayer);
AF_DEFINE(BaseBrush);
AF_DEFINE(BaseCmd);
AF_DEFINE(BaseEffect);
AF_DEFINE(BaseGlys);
AF_DEFINE(BaseAtt);
AF_DEFINE(BaseProp);
AF_DEFINE(BaseDels);
AF_DEFINE(BaseFrms);
AF_DEFINE(BaseFilt);
AF_DEFINE(BaseScObjs);
AF_DEFINE(BaseShape);
AF_DEFINE(BaseSubSel);
AF_DEFINE(v_3DLA);
AF_DEFINE(ACrt);
AF_DEFINE(AFAt);
AF_DEFINE(ARCm);
AF_DEFINE(AbMp);
AF_DEFINE(Adjs);
AF_DEFINE(ApVs);
AF_DEFINE(ArFr);
AF_DEFINE(AstP);
AF_DEFINE(BCRA);
AF_DEFINE(BWRA);
AF_DEFINE(BlnR);
AF_DEFINE(BmRB);
AF_DEFINE(Brus);
AF_DEFINE(CBRA);
AF_DEFINE(CMRA);
AF_DEFINE(CMTC);
AF_DEFINE(CPTx);
AF_DEFINE(ChGl);
AF_DEFINE(ClrX);
AF_DEFINE(CoDe);
AF_DEFINE(CoFr);
AF_DEFINE(Comp);
AF_DEFINE(CrPP);
AF_DEFINE(CrRA);
AF_DEFINE(CrvD);
AF_DEFINE(CrvP);
AF_DEFINE(CvHS);
AF_DEFINE(DDef);
AF_DEFINE(DHis);
AF_DEFINE(DPOp);
AF_DEFINE(DcMD);
AF_DEFINE(DeSy);
AF_DEFINE(Deco);
AF_DEFINE(DocN);
AF_DEFINE(DrCp);
AF_DEFINE(Dupl);
AF_DEFINE(DyBm);
AF_DEFINE(EDfP);
AF_DEFINE(EOJp);
AF_DEFINE(EOPS);
AF_DEFINE(EOPn);
AF_DEFINE(EOSv);
AF_DEFINE(ExBB);
AF_DEFINE(ExCS);
AF_DEFINE(ExCV);
AF_DEFINE(ExCm);
AF_DEFINE(ExEq);
AF_DEFINE(ExRA);
AF_DEFINE(ExRS);
AF_DEFINE(ExSc);
AF_DEFINE(FDsc);
AF_DEFINE(FExO);
AF_DEFINE(FilG);
AF_DEFINE(FilN);
AF_DEFINE(FilS);
AF_DEFINE(Filp);
AF_DEFINE(FntM);
AF_DEFINE(ForC);
AF_DEFINE(GStr);
AF_DEFINE(GlAS);
AF_DEFINE(GrRA);
AF_DEFINE(Grup);
AF_DEFINE(ICCP);
AF_DEFINE(LSty);
AF_DEFINE(LigS);
AF_DEFINE(MPIN);
AF_DEFINE(MRst);
AF_DEFINE(Macr);
AF_DEFINE(MgDC);
AF_DEFINE(ObjS);
AF_DEFINE(OpAV);
AF_DEFINE(PCrv);
AF_DEFINE(PLig);
AF_DEFINE(PTCP);
AF_DEFINE(PTCf);
AF_DEFINE(PTEq);
AF_DEFINE(PTNd);
AF_DEFINE(PfPr);
AF_DEFINE(Prst);
AF_DEFINE(Quad);
AF_DEFINE(RGBA);
AF_DEFINE(RRBr);
AF_DEFINE(Rstr);
AF_DEFINE(SGrP);
AF_DEFINE(SPPp);
AF_DEFINE(SPRA);
AF_DEFINE(SPst);
AF_DEFINE(SRst);
AF_DEFINE(ScRN);
AF_DEFINE(Scop);
AF_DEFINE(Sele);
AF_DEFINE(ShCE);
AF_DEFINE(ShCR);
AF_DEFINE(ShCg);
AF_DEFINE(ShCl);
AF_DEFINE(ShCr);
AF_DEFINE(ShDA);
AF_DEFINE(ShDS);
AF_DEFINE(ShHt);
AF_DEFINE(ShNR);
AF_DEFINE(ShPi);
AF_DEFINE(ShPy);
AF_DEFINE(ShSS);
AF_DEFINE(ShSg);
AF_DEFINE(ShSt);
AF_DEFINE(ShTr);
AF_DEFINE(ShTz);
AF_DEFINE(ShpD);
AF_DEFINE(ShpN);
AF_DEFINE(ShpT);
AF_DEFINE(SlcP);
AF_DEFINE(Slic);
AF_DEFINE(SnpG);
AF_DEFINE(SpRe);
AF_DEFINE(SpTA);
AF_DEFINE(Sprd);
AF_DEFINE(TBFR);
AF_DEFINE(TBSO);
AF_DEFINE(TExM);
AF_DEFINE(TStS);
AF_DEFINE(TSty);
AF_DEFINE(TabS);
AF_DEFINE(TbFt);
AF_DEFINE(TexS);
AF_DEFINE(ThRA);
AF_DEFINE(TocA);
AF_DEFINE(TonP);
AF_DEFINE(TxFl);
AF_DEFINE(TxtA);
AF_DEFINE(TxtF);
AF_DEFINE(TxtT);
AF_DEFINE(UVCn);
AF_DEFINE(UndR);
AF_DEFINE(Undo);
AF_DEFINE(VbRA);
AF_DEFINE(VwPD);
AF_DEFINE(WBRA);
AF_DEFINE(v_CB1);
AF_DEFINE(v_CB2);
AF_DEFINE(v_CB4);
AF_DEFINE(v_CB5);
AF_DEFINE(v_C1);
AF_DEFINE(v_C2);

AF_STRUCT_INIT(HSLA)
{
	AF_INIT_BASE(BaseColor);

	AF_INIT_S(v_col, 0x5F636F6Cu, AffinityReader::ColorHSLA);
}

AF_STRUCT_INIT(HSSP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(HueA, 0x48756541u, float);
	AF_INIT_S(SatA, 0x53617441u, float);
	AF_INIT_S(LumA, 0x4C756D41u, float);
	AF_INIT_V(HueC, 0x48756543u, AffinityReader::SharedArray<float>);
	AF_INIT_V(SatC, 0x53617443u, AffinityReader::SharedArray<float>);
	AF_INIT_V(LumC, 0x4C756D43u, AffinityReader::SharedArray<float>);
	AF_INIT_V(RngC, 0x526E6743u, AffinityReader::SharedArray<float>);
	AF_INIT_S(HSV, 0x48535620u, bool);
}

AF_STRUCT_INIT(HlkA)
{
	AF_INIT_BASE(BaseFill);

	AF_INIT_N(Data);
}

AF_STRUCT_INIT(HsRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(IBRB)
{
	AF_INIT_BASE(BaseBrush);
}

AF_STRUCT_INIT(ICC)
{
	AF_INIT_C(RGBP, 0x52474250u, ICCP);
	AF_INIT_C(RGUP, 0x52475550u, ICCP);
	AF_INIT_C(CMYP, 0x434D5950u, ICCP);
	AF_INIT_C(IAPr, 0x49415072u, ICCP);
	AF_INIT_C(LABP, 0x4C414250u, ICCP);
	AF_INIT_S(Intn, 0x496E746Eu, AffinityReader::EnumT);
	AF_INIT_S(BPCm, 0x4250436Du, bool);
}

AF_STRUCT_INIT(ICCP)
{
	AF_INIT_S(Data, 0x44617461u, AffinityReader::BinaryData);
}

AF_STRUCT_INIT(ILDO)
{
	AF_INIT_X(0x494C4F62u, {
		AF_CASE_X(ILOb, 0x50437276u, PCrv);
		AF_CASE_X(ILOb, 0x5368704Eu, ShpN);
	});
}

AF_STRUCT_INIT(ILGI)
{
	AF_INIT_X(0x494C4F62u, {
		AF_CASE_X(ILOb, 0x436F6D70u, Comp);
		AF_CASE_X(ILOb, 0x47727570u, Grup);
		AF_CASE_X(ILOb, 0x4D50494Eu, MPIN);
		AF_CASE_X(ILOb, 0x4D527374u, MRst);
		AF_CASE_X(ILOb, 0x50437276u, PCrv);
		AF_CASE_X(ILOb, 0x52737472u, Rstr);
		AF_CASE_X(ILOb, 0x53636F70u, Scop);
		AF_CASE_X(ILOb, 0x5368704Eu, ShpN);
		AF_CASE_X(ILOb, 0x53707264u, Sprd);
		AF_CASE_X(ILOb, 0x54787441u, TxtA);
		AF_CASE_X(ILOb, 0x54787446u, TxtF);
	});
}

AF_STRUCT_INIT(ILSN)
{
	AF_INIT_X(0x494C4F62u, {
		AF_CASE_X(ILOb, 0x436F6D70u, Comp);
		AF_CASE_X(ILOb, 0x47727570u, Grup);
		AF_CASE_X(ILOb, 0x4D50494Eu, MPIN);
		AF_CASE_X(ILOb, 0x4D527374u, MRst);
		AF_CASE_X(ILOb, 0x50437276u, PCrv);
		AF_CASE_X(ILOb, 0x52737472u, Rstr);
		AF_CASE_X(ILOb, 0x53636F70u, Scop);
		AF_CASE_X(ILOb, 0x5368704Eu, ShpN);
		AF_CASE_X(ILOb, 0x53707264u, Sprd);
		AF_CASE_X(ILOb, 0x54787441u, TxtA);
		AF_CASE_X(ILOb, 0x54787446u, TxtF);
	});
}

AF_STRUCT_INIT(ILTI)
{
	AF_INIT_X(0x494C4F62u, {
		AF_CASE_X(ILOb, 0x436F6D70u, Comp);
		AF_CASE_X(ILOb, 0x47727570u, Grup);
		AF_CASE_X(ILOb, 0x4D527374u, MRst);
		AF_CASE_X(ILOb, 0x50437276u, PCrv);
		AF_CASE_X(ILOb, 0x52737472u, Rstr);
		AF_CASE_X(ILOb, 0x53636F70u, Scop);
		AF_CASE_X(ILOb, 0x5368704Eu, ShpN);
		AF_CASE_X(ILOb, 0x54787441u, TxtA);
		AF_CASE_X(ILOb, 0x54787446u, TxtF);
	});
}

AF_STRUCT_INIT(ILTf)
{
	AF_INIT_L(ILOb, 0x494C4F62u, TxFl);
}

AF_STRUCT_INIT(ImgN)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(ExtT, 0x45787454u, AffinityReader::EnumT);
	AF_INIT_S(ResT, 0x52657354u, AffinityReader::EnumT);
	AF_INIT_S(StkU, 0x53746B55u, std::string);
	AF_INIT_S(uPro, 0x7550726Fu, std::string);
	AF_INIT_S(StAu, 0x53744175u, std::string);
	AF_INIT_S(ODPI, 0x4F445049u, int32_t);
	AF_INIT_S(ICCP, 0x49434350u, std::string);
	AF_INIT_S(Orig, 0x4F726967u, AffinityReader::EmbeddedData);
}

AF_STRUCT_INIT(InGl)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(TSel, 0x5453656Cu, bool);
	AF_INIT_S(Togl, 0x546F676Cu, bool);
	AF_INIT_S(PrNc, 0x50724E63u, bool);
	AF_INIT_C(OldS, 0x4F6C6453u, Sele);
}

AF_STRUCT_INIT(InRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(Indx)
{
	AF_INIT_E(Tpcs);
	AF_INIT_E(OrTp);
	AF_INIT_S(Sort, 0x536F7274u, std::string);
	AF_INIT_S(Lang, 0x4C616E67u, std::string);
	AF_INIT_S(InSH, 0x496E5348u, bool);
	AF_INIT_S(GpPR, 0x47705052u, bool);
	AF_INIT_S(ExpX, 0x45787058u, bool);
	AF_INIT_S(SAfT, 0x53416654u, std::string);
	AF_INIT_S(SBtI, 0x53427449u, std::string);
	AF_INIT_S(SBtR, 0x53427452u, std::string);
	AF_INIT_S(SBfX, 0x53426658u, std::string);
	AF_INIT_S(SSee, 0x53536565u, std::string);
	AF_INIT_S(SSeA, 0x53536541u, std::string);
	AF_INIT_S(SAfX, 0x53416658u, std::string);
}

AF_STRUCT_INIT(InnG)
{
	AF_INIT_BASE(BaseEffect);

	AF_INIT_S(Cntr, 0x436E7472u, bool);
}

AF_STRUCT_INIT(InnS)
{
	AF_INIT_BASE(BaseEffect);
}

AF_STRUCT_INIT(LABA)
{
	AF_INIT_BASE(BaseColor);

	AF_INIT_S(v_col, 0x5F636F6Cu, AffinityReader::ColorLABA);
}

AF_STRUCT_INIT(LDsc)
{
	AF_INIT_BASE(BaseFill);

	AF_INIT_C(LDeL, 0x4C44654Cu, LSty);
	AF_INIT_S(LDBe, 0x4C444265u, bool);
	AF_INIT_S(LDSc, 0x4C445363u, bool);
	AF_INIT_C(LDeP, 0x4C446550u, CrvD);
	AF_INIT_S(LDSa, 0x4C445361u, int32_t);
	AF_INIT_S(LIAh, 0x4C494168u, bool);
}

AF_STRUCT_INIT(LLGl)
{
	AF_INIT_BASE(BaseGlys);

	AF_INIT_S(Levl, 0x4C65766Cu, int32_t);
}

AF_STRUCT_INIT(LR3D)
{
	AF_INIT_S(Blob, 0x426C6F62u, AffinityReader::EmbeddedData);
	AF_INIT_S(Dime, 0x44696D65u, int32_t);
	AF_INIT_V(Pxls, 0x50786C73u, AffinityReader::SharedArray<float>);
	AF_INIT_S(Name, 0x4E616D65u, std::string);
}

AF_STRUCT_INIT(LStr)
{
	AF_INIT_S(Str_, 0x5374725Fu, std::string);
	AF_INIT_S(Ctxt, 0x43747874u, std::string);
}

AF_STRUCT_INIT(LSty)
{
	AF_INIT_S(Data, 0x44617461u, AffinityReader::curve12_t);
	AF_INIT_S(Wght, 0x57676874u, double);
	AF_INIT_M(0x42727573u, {
		AF_CASE_M(Brus, 0x426D5242u, BmRB);
		AF_CASE_M(Brus, 0x49425242u, IBRB);
		AF_CASE_M(Brus, 0x52524272u, RRBr);
	});
	AF_INIT_S(Phse, 0x50687365u, double);
	AF_INIT_V(Patn, 0x5061746Eu, AffinityReader::SharedArray<double>);
}

AF_STRUCT_INIT(Layt)
{
	AF_INIT_X(0x46726D73u, {
		AF_CASE_X(Frms, 0x41724672u, ArFr);
		AF_CASE_X(Frms, 0x436F4672u, CoFr);
	});
}

AF_STRUCT_INIT(LeFP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(L_, 0x4C5F5F5Fu, uint16_t);
	AF_INIT_S(A_, 0x415F5F5Fu, uint16_t);
	AF_INIT_S(B_, 0x425F5F5Fu, uint16_t);
	AF_INIT_S(Dens, 0x44656E73u, float);
	AF_INIT_S(Pres, 0x50726573u, bool);
}

AF_STRUCT_INIT(LeRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(LevP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(Blac, 0x426C6163u, float);
	AF_INIT_S(Whit, 0x57686974u, float);
	AF_INIT_S(OutB, 0x4F757442u, float);
	AF_INIT_S(OutW, 0x4F757457u, float);
	AF_INIT_V(BlkC, 0x426C6B43u, AffinityReader::SharedArray<float>);
	AF_INIT_V(WhtC, 0x57687443u, AffinityReader::SharedArray<float>);
	AF_INIT_V(GamC, 0x47616D43u, AffinityReader::SharedArray<float>);
	AF_INIT_V(OBlC, 0x4F426C43u, AffinityReader::SharedArray<float>);
	AF_INIT_V(OWhC, 0x4F576843u, AffinityReader::SharedArray<float>);
}

AF_STRUCT_INIT(LigP)
{
	AF_INIT_S(Ambi, 0x416D6269u, double);
	AF_INIT_S(Diff, 0x44696666u, double);
	AF_INIT_S(Spec, 0x53706563u, double);
	AF_INIT_S(Expo, 0x4578706Fu, double);
	AF_INIT_C(AmbC, 0x416D6243u, RGBA);
	AF_INIT_C(SpeC, 0x53706543u, HSLA);
	AF_INIT_S(Dept, 0x44657074u, double);
	AF_INIT_N(BMap);
	AF_INIT_S(ScaX, 0x53636158u, bool);
	AF_INIT_S(ScaY, 0x53636159u, bool);
	AF_INIT_S(BMOp, 0x424D4F70u, double);
	AF_INIT_L(Lits, 0x4C697473u, LigS);
}

AF_STRUCT_INIT(LigS)
{
	AF_INIT_S(Type, 0x54797065u, AffinityReader::EnumT);
	AF_INIT_C(Colo, 0x436F6C6Fu, RGBA);
	AF_INIT_S(Spin, 0x5370696Eu, double);
	AF_INIT_S(Tilt, 0x54696C74u, double);
	AF_INIT_A(Cent, 0x43656E74u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(Dist, 0x44697374u, double);
	AF_INIT_S(OCon, 0x4F436F6Eu, double);
	AF_INIT_S(ICon, 0x49436F6Eu, double);
}

AF_STRUCT_INIT(LisA)
{
	AF_INIT_BASE(BaseAtt);

	AF_INIT_S(Type, 0x54797065u, AffinityReader::EnumT);
	AF_INIT_S(Id, 0x49642020u, int32_t);
	AF_INIT_S(Levl, 0x4C65766Cu, int32_t);
	AF_INIT_V(IStr, 0x49537472u, AffinityReader::SharedArray<double>);
	AF_INIT_S(ITxt, 0x49547874u, double);
	AF_INIT_C(Strn, 0x5374726Eu, GStr);
	AF_INIT_C(Sepr, 0x53657072u, GStr);
	AF_INIT_S(Scal, 0x5363616Cu, double);
	AF_INIT_S(OffY, 0x4F666659u, double);
	AF_INIT_S(Alig, 0x416C6967u, AffinityReader::EnumT);
	AF_INIT_S(NFmt, 0x4E466D74u, AffinityReader::EnumT);
	AF_INIT_S(Strt, 0x53747274u, int32_t);
	AF_INIT_S(Tier, 0x54696572u, bool);
	AF_INIT_S(ITab, 0x49546162u, double);
	AF_INIT_C(BulS, 0x42756C53u, GStr);
	AF_INIT_C(NumS, 0x4E756D53u, GStr);
	AF_INIT_S(ResT, 0x52657354u, AffinityReader::EnumT);
	AF_INIT_S(ResL, 0x5265734Cu, int32_t);
}

AF_STRUCT_INIT(LoDO)
{
	AF_INIT_S(Page, 0x50616765u, int32_t);
	AF_INIT_S(IFET, 0x49464554u, bool);
	AF_INIT_S(TxGr, 0x54784772u, bool);
	AF_INIT_C(FoMp, 0x466F4D70u, FntM);
	AF_INIT_S(dpi, 0x64706920u, double);
	AF_INIT_S(ClSp, 0x436C5370u, AffinityReader::EnumT);
	AF_INIT_V(Pags, 0x50616773u, AffinityReader::SharedArray<int32_t>);
}

AF_STRUCT_INIT(MC2C)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_A(Delt, 0x44656C74u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_A(Dlt2, 0x446C7432u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(SOcr, 0x534F6372u, bool);
	AF_INIT_S(Clos, 0x436C6F73u, bool);
	AF_INIT_S(ClSt, 0x436C5374u, bool);
	AF_INIT_L(Undo, 0x556E646Fu, Undo);
	AF_INIT_E(OCrv);
	AF_INIT_N(ORCv);
	AF_INIT_C(OldS, 0x4F6C6453u, Sele);
	AF_INIT_S(OmLN, 0x4F6D4C4Eu, bool);
}

AF_STRUCT_INIT(MPIN)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(PgOf, 0x50674F66u, uint32_t);
	AF_INIT_S(MPOf, 0x4D504F66u, uint32_t);
	AF_INIT_S(PgCt, 0x50674374u, uint32_t);
	AF_INIT_S(ScMd, 0x53634D64u, AffinityReader::EnumT);
}

AF_STRUCT_INIT(MRst)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(MacI)
{
	AF_INIT_M(0x436D6420u, {
		AF_CASE_M(Cmd, 0x4152436Du, ARCm);
		AF_CASE_M(Cmd, 0x434D5443u, CMTC);
		AF_CASE_M(Cmd, 0x436C7258u, ClrX);
		AF_CASE_M(Cmd, 0x466F7243u, ForC);
		AF_CASE_M(Cmd, 0x4D674443u, MgDC);
	});
	AF_INIT_S(Enab, 0x456E6162u, bool);
	AF_INIT_A(Sprd, 0x53707264u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_V(FavP, 0x46617650u, AffinityReader::SharedArray<uint64_t>);
	AF_INIT_V(MUID, 0x4D554944u, AffinityReader::SharedArray<uint64_t>);
	AF_INIT_E(MSpl);
}

AF_STRUCT_INIT(MacP)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_C(Macr, 0x4D616372u, Macr);
}

AF_STRUCT_INIT(Macr)
{
	AF_INIT_L(Macr, 0x4D616372u, MacI);
	AF_INIT_S(Desc, 0x44657363u, std::string);
}

AF_STRUCT_INIT(Matx)
{
	AF_INIT_S(Rows, 0x526F7773u, int32_t);
	AF_INIT_S(Cols, 0x436F6C73u, int32_t);
	AF_INIT_V(Data, 0x44617461u, AffinityReader::SharedArray<double>);
}

AF_STRUCT_INIT(MgDC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_N(SrcN);
	AF_INIT_N(DstN);
	AF_INIT_N(OldS);
	AF_INIT_N(OldP);
	AF_INIT_N(OlSi);
	AF_INIT_N(Cach);
	AF_INIT_S(Freq, 0x46726571u, bool);
}

AF_STRUCT_INIT(MvNC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Type, 0x54797065u, AffinityReader::EnumT);
	AF_INIT_S(CLiT, 0x434C6954u, AffinityReader::EnumT);
	AF_INIT_M(0x44657374u, {
		AF_CASE_M(Dest, 0x47727570u, Grup);
		AF_CASE_M(Dest, 0x52737472u, Rstr);
		AF_CASE_M(Dest, 0x5368704Eu, ShpN);
	});
	AF_INIT_X(0x4F6C6450u, {
		AF_CASE_X(OldP, 0x47727570u, Grup);
		AF_CASE_X(OldP, 0x5368704Eu, ShpN);
		AF_CASE_X(OldP, 0x53707264u, Sprd);
	});
	AF_INIT_V(OldC, 0x4F6C6443u, AffinityReader::SharedArray<AffinityReader::EnumT>);
	AF_INIT_S(RACt, 0x52414374u, bool);
	AF_INIT_V(OlTS, 0x4F6C5453u, AffinityReader::SharedArray<bool>);
	AF_INIT_S(FrKA, 0x46724B41u, bool);
	AF_INIT_X(0x44744C4Fu, {
		AF_CASE_X(DtLO, 0x47727570u, Grup);
		AF_CASE_X(DtLO, 0x52737472u, Rstr);
		AF_CASE_X(DtLO, 0x5368704Eu, ShpN);
		AF_CASE_X(DtLO, 0x53707264u, Sprd);
	});
	AF_INIT_V(DtLF, 0x44744C46u, AffinityReader::SharedArray<bool>);
}

AF_STRUCT_INIT(OCRN)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(OSty)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_C(OSty, 0x4F537479u, ObjS);
}

AF_STRUCT_INIT(OTFD)
{
	AF_INIT_BASE(BaseDels);

	AF_INIT_L(Feat, 0x46656174u, UndR);
	AF_INIT_S(cler, 0x636C6572u, bool);
	AF_INIT_C(LDsc, 0x4C447363u, LStr);
}

AF_STRUCT_INIT(OTFS)
{
	AF_INIT_S(Feat, 0x46656174u, uint32_t);
	AF_INIT_S(Valu, 0x56616C75u, int32_t);
}

AF_STRUCT_INIT(ObSB)
{
	AF_INIT_S(Cont, 0x436F6E74u, AffinityReader::EnumT);
	AF_INIT_S(BFCr, 0x42464372u, uint32_t);
	AF_INIT_L(BFFl, 0x4246466Cu, FDsc);
	AF_INIT_M(0x4246696Cu, {
		AF_CASE_M(BFil, 0x46447363u, FDsc);
		AF_CASE_M(BFil, 0x46696C53u, FilS);
	});
}

AF_STRUCT_INIT(ObSL)
{
	AF_INIT_S(Cont, 0x436F6E74u, AffinityReader::EnumT);
	AF_INIT_S(LICr, 0x4C494372u, uint32_t);
	AF_INIT_L(LILn, 0x4C494C6Eu, LDsc);
	AF_INIT_L(LIFl, 0x4C49466Cu, FDsc);
	AF_INIT_C(LSty, 0x4C537479u, LDsc);
	AF_INIT_M(0x5046696Cu, {
		AF_CASE_M(PFil, 0x46447363u, FDsc);
		AF_CASE_M(PFil, 0x46696C53u, FilS);
	});
}

AF_STRUCT_INIT(ObST)
{
	AF_INIT_S(Cont, 0x436F6E74u, AffinityReader::EnumT);
}

AF_STRUCT_INIT(ObjS)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(HsFE, 0x48734645u, bool);
	AF_INIT_S(HsBM, 0x4873424Du, bool);
	AF_INIT_S(HsVi, 0x48735669u, bool);
	AF_INIT_S(HsTW, 0x48735457u, bool);
	AF_INIT_S(HsDO, 0x4873444Fu, bool);
	AF_INIT_S(Frmt, 0x46726D74u, AffinityReader::EnumT);
	AF_INIT_C(RGBP, 0x52474250u, ICCP);
	AF_INIT_N(CMYK);
	AF_INIT_C(MBru, 0x4D427275u, ObSB);
	AF_INIT_C(MLin, 0x4D4C696Eu, ObSL);
	AF_INIT_C(MTra, 0x4D547261u, ObST);
	AF_INIT_C(FLin, 0x464C696Eu, ObSL);
	AF_INIT_C(FBru, 0x46427275u, ObSB);
	AF_INIT_C(FTra, 0x46547261u, ObST);
	AF_INIT_N(GlyA);
	AF_INIT_N(ParA);
	AF_INIT_S(OSNE, 0x4F534E45u, bool);
	AF_INIT_S(HsPF, 0x48735046u, bool);
	AF_INIT_N(SNPR);
}

AF_STRUCT_INIT(OpAA)
{
	AF_INIT_BASE(BaseFill);

	AF_INIT_L(Vals, 0x56616C73u, OpAV);
}

AF_STRUCT_INIT(OpAV)
{
	AF_INIT_S(Glyp, 0x476C7970u, std::string);
	AF_INIT_S(Left, 0x4C656674u, double);
}

AF_STRUCT_INIT(OtAt)
{
	AF_INIT_BASE(BaseFill);

	AF_INIT_L(Setn, 0x5365746Eu, OTFS);
}

AF_STRUCT_INIT(OutG)
{
	AF_INIT_BASE(BaseEffect);
}

AF_STRUCT_INIT(PADD)
{
	AF_INIT_BASE(BaseDels);

	AF_INIT_S(Valu, 0x56616C75u, double);
}

AF_STRUCT_INIT(PADS)
{
	AF_INIT_BASE(BaseDels);

	AF_INIT_S(Valu, 0x56616C75u, std::string);
}

AF_STRUCT_INIT(PAID)
{
	AF_INIT_BASE(BaseDels);

	AF_INIT_S(Valu, 0x56616C75u, int32_t);
}

AF_STRUCT_INIT(PAOD)
{
	AF_INIT_BASE(BaseDels);

	AF_INIT_M(0x56616C75u, {
		AF_CASE_M(Valu, 0x4465636Fu, Deco);
		AF_CASE_M(Valu, 0x4C697341u, LisA);
		AF_CASE_M(Valu, 0x54616253u, TabS);
	});
}

AF_STRUCT_INIT(PAtt)
{
	AF_INIT_V(Ints, 0x496E7473u, AffinityReader::SharedArray<int32_t>);
	AF_INIT_V(Doub, 0x446F7562u, AffinityReader::SharedArray<double>);
	AF_INIT_V(Stri, 0x53747269u, AffinityReader::SharedArray<std::string>);
	AF_INIT_X(0x4F626A73u, {
		AF_CASE_X(Objs, 0x41464174u, AFAt);
		AF_CASE_X(Objs, 0x4465636Fu, Deco);
		AF_CASE_X(Objs, 0x44724370u, DrCp);
		AF_CASE_X(Objs, 0x4C697341u, LisA);
		AF_CASE_X(Objs, 0x54616253u, TabS);
		AF_CASE_X(Objs, 0x546F6341u, TocA);
	});
}

AF_STRUCT_INIT(PBxR)
{
	AF_INIT_V(rcts, 0x72637473u, AffinityReader::SharedArray<AffinityReader::vec_d_t<4>>);
}

AF_STRUCT_INIT(PCFl)
{
	AF_INIT_S(MUID, 0x4D554944u, uint32_t);
	AF_INIT_S(MChk, 0x4D43686Bu, int64_t);
	AF_INIT_S(UChk, 0x5543686Bu, int64_t);
	AF_INIT_S(NUID, 0x4E554944u, uint32_t);
	AF_INIT_C(Root, 0x526F6F74u, PTNd);
}

AF_STRUCT_INIT(PCrv)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_C(MCrM, 0x4D43724Du, PCrv);
}

AF_STRUCT_INIT(PCvD)
{
	AF_INIT_C(Data, 0x44617461u, v_CB1);
	AF_INIT_C(CnrD, 0x436E7244u, v_CB2);
}

AF_STRUCT_INIT(PLef)
{
	AF_INIT_S(Name, 0x4E616D65u, std::string);
	AF_INIT_S(ONam, 0x4F4E616Du, std::string);
	AF_INIT_S(DNam, 0x444E616Du, std::string);
	AF_INIT_S(v_UID, 0x5F554944u, uint32_t);
	AF_INIT_S(OUID, 0x4F554944u, uint32_t);
	AF_INIT_M(0x50726F70u, {
		AF_CASE_M(Prop, 0x41437274u, ACrt);
		AF_CASE_M(Prop, 0x41624D70u, AbMp);
		AF_CASE_M(Prop, 0x41646A73u, Adjs);
		AF_CASE_M(Prop, 0x41737450u, AstP);
		AF_CASE_M(Prop, 0x42727573u, Brus);
		AF_CASE_M(Prop, 0x43725050u, CrPP);
		AF_CASE_M(Prop, 0x44504F70u, DPOp);
		AF_CASE_M(Prop, 0x46696C70u, Filp);
		AF_CASE_M(Prop, 0x4D616350u, MacP);
		AF_CASE_M(Prop, 0x4F537479u, OSty);
		AF_CASE_M(Prop, 0x50544350u, PTCP);
		AF_CASE_M(Prop, 0x50665072u, PfPr);
		AF_CASE_M(Prop, 0x53477250u, SGrP);
		AF_CASE_M(Prop, 0x53505070u, SPPp);
		AF_CASE_M(Prop, 0x5445784Du, TExM);
		AF_CASE_M(Prop, 0x546F6E50u, TonP);
	});
}

AF_STRUCT_INIT(PLiA)
{
	AF_INIT_L(PLis, 0x504C6973u, PLig);
}

AF_STRUCT_INIT(PLig)
{
	AF_INIT_S(Alph, 0x416C7068u, double);
	AF_INIT_S(Beta, 0x42657461u, double);
	AF_INIT_C(Colo, 0x436F6C6Fu, HSLA);
}

AF_STRUCT_INIT(PNoC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Form, 0x466F726Du, AffinityReader::EnumT);
	AF_INIT_C(RGBS, 0x52474253u, ICCP);
	AF_INIT_C(CMYS, 0x434D5953u, ICCP);
	AF_INIT_C(IA_S, 0x49415F53u, ICCP);
	AF_INIT_C(LABS, 0x4C414253u, ICCP);
	AF_INIT_A(VPRc, 0x56505263u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_S(Tagg, 0x54616767u, bool);
	AF_INIT_N(DCmd);
	AF_INIT_N(TCmd);
	AF_INIT_C(OSel, 0x4F53656Cu, Sele);
	AF_INIT_A(OCRc, 0x4F435263u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_C(OldS, 0x4F6C6453u, Sele);
}

AF_STRUCT_INIT(PRNS)
{
	AF_INIT_BASE(BaseCmd);
}

AF_STRUCT_INIT(PSRe)
{
	AF_INIT_N(Mstr);
	AF_INIT_N(FSlv);
}

AF_STRUCT_INIT(PTCP)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_C(Cnfg, 0x436E6667u, PTCf);
	AF_INIT_L(Prst, 0x50727374u, Prst);
}

AF_STRUCT_INIT(PTCf)
{
	AF_INIT_L(eqns, 0x65716E73u, PTEq);
	AF_INIT_C(cnst, 0x636E7374u, ExCS);
	AF_INIT_S(cfmt, 0x63666D74u, AffinityReader::EnumT);
	AF_INIT_S(rads, 0x72616473u, bool);
}

AF_STRUCT_INIT(PTEq)
{
	AF_INIT_C(eqtn, 0x6571746Eu, ExEq);
	AF_INIT_S(mask, 0x6D61736Bu, uint32_t);
}

AF_STRUCT_INIT(PTNd)
{
	AF_INIT_S(CUID, 0x43554944u, uint32_t);
	AF_INIT_S(Usge, 0x55736765u, uint32_t);
	AF_INIT_S(v_UID, 0x5F554944u, uint32_t);
	AF_INIT_S(OUID, 0x4F554944u, uint32_t);
	AF_INIT_S(Name, 0x4E616D65u, std::string);
	AF_INIT_S(ONam, 0x4F4E616Du, std::string);
	AF_INIT_S(DNam, 0x444E616Du, std::string);
	AF_INIT_L(Levs, 0x4C657673u, PLef);
	AF_INIT_L(Chld, 0x43686C64u, PTNd);
	AF_INIT_S(CIdx, 0x43496478u, uint32_t);
}

AF_STRUCT_INIT(PTRt)
{
	AF_INIT_S(NUID, 0x4E554944u, uint32_t);
	AF_INIT_C(Root, 0x526F6F74u, PTNd);
}

AF_STRUCT_INIT(PaAR)
{
	AF_INIT_S(Indx, 0x496E6478u, int32_t);
	AF_INIT_C(Item, 0x4974656Du, PAtt);
}

AF_STRUCT_INIT(PaAS)
{
	AF_INIT_L(Runs, 0x52756E73u, PaAR);
}

AF_STRUCT_INIT(PaFr)
{
	AF_INIT_BASE(BaseFrms);

	AF_INIT_C(PCrv, 0x50437276u, PCvD);
	AF_INIT_V(Revr, 0x52657672u, AffinityReader::SharedArray<bool>);
	AF_INIT_V(Strt, 0x53747274u, AffinityReader::SharedArray<double>);
	AF_INIT_V(Ends, 0x456E6473u, AffinityReader::SharedArray<double>);
	AF_INIT_V(Advc, 0x41647663u, AffinityReader::SharedArray<double>);
}

AF_STRUCT_INIT(Pano)
{
	AF_INIT_V(byte, 0x62797465u, AffinityReader::SharedArray<uint8_t>);
}

AF_STRUCT_INIT(Pant)
{
	AF_INIT_BASE(BaseColor);

	AF_INIT_M(0x62617365u, {
		AF_CASE_M(base, 0x48534C41u, HSLA);
		AF_CASE_M(base, 0x4C414241u, LABA);
		AF_CASE_M(base, 0x52474241u, RGBA);
	});
	AF_INIT_C(srgb, 0x73726762u, RGBA);
	AF_INIT_S(ispt, 0x69737074u, bool);
	AF_INIT_S(name, 0x6E616D65u, std::string);
}

AF_STRUCT_INIT(Per_42)
{
	AF_INIT_L(Pers, 0x50657273u, Quad);
	AF_INIT_S(Curr, 0x43757272u, int32_t);
}

AF_STRUCT_INIT(Pers)
{
	AF_INIT_C(OVer, 0x4F566572u, ApVs);
	AF_INIT_C(NVer, 0x4E566572u, ApVs);
	AF_INIT_C(DocR, 0x446F6352u, DocN);
	AF_INIT_C(EdRt, 0x45645274u, Sprd);
	AF_INIT_C(CSel, 0x4353656Cu, Sele);
	AF_INIT_C(SlBQ, 0x536C4251u, Sele);
	AF_INIT_M(0x434C7972u, {
		AF_CASE_M(CLyr, 0x53636F70u, Scop);
		AF_CASE_M(CLyr, 0x5368704Eu, ShpN);
		AF_CASE_M(CLyr, 0x53707264u, Sprd);
	});
	AF_INIT_C(RasS, 0x52617353u, SRst);
	AF_INIT_L(Symb, 0x53796D62u, Grup);
	AF_INIT_X(0x52466C6Cu, {
		AF_CASE_X(RFll, 0x46696C47u, FilG);
		AF_CASE_X(RFll, 0x46696C4Eu, FilN);
		AF_CASE_X(RFll, 0x46696C53u, FilS);
	});
	AF_INIT_C(DFll, 0x44466C6Cu, PTRt);
	AF_INIT_C(DDFl, 0x4444466Cu, DDef);
	AF_INIT_L(PrPr, 0x50725072u, CrvD);
	AF_INIT_S(v_32Un, 0x3332556Eu, bool);
	AF_INIT_S(OCIO, 0x4F43494Fu, std::string);
	AF_INIT_S(OCIV, 0x4F434956u, std::string);
	AF_INIT_M(0x4446454Fu, {
		AF_CASE_M(DFEO, 0x454F4A70u, EOJp);
		AF_CASE_M(DFEO, 0x454F5053u, EOPS);
		AF_CASE_M(DFEO, 0x454F506Eu, EOPn);
		AF_CASE_M(DFEO, 0x454F5376u, EOSv);
		AF_CASE_M(DFEO, 0x4645784Fu, FExO);
	});
	AF_INIT_S(XMPM, 0x584D504Du, std::string);
	AF_INIT_C(UVCn, 0x5556436Eu, UVCn);
	AF_INIT_S(UntT, 0x556E7454u, uint8_t);
	AF_INIT_S(DDRF, 0x44445246u, AffinityReader::EnumT);
	AF_INIT_S(EdAL, 0x4564414Cu, bool);
	AF_INIT_S(CCFm, 0x4343466Du, bool);
	AF_INIT_S(PrCC, 0x50724343u, bool);
	AF_INIT_S(PrFC, 0x50724643u, bool);
	AF_INIT_C(IAPr, 0x49415072u, ICCP);
	AF_INIT_C(CMYP, 0x434D5950u, ICCP);
	AF_INIT_C(LABP, 0x4C414250u, ICCP);
	AF_INIT_C(RGBP, 0x52474250u, ICCP);
	AF_INIT_C(RGUP, 0x52475550u, ICCP);
	AF_INIT_S(Intn, 0x496E746Eu, AffinityReader::EnumT);
	AF_INIT_S(BPCm, 0x4250436Du, bool);
	AF_INIT_S(SnUT, 0x536E5554u, uint8_t);
	AF_INIT_S(USnG, 0x55536E47u, bool);
	AF_INIT_C(SGrd, 0x53477264u, SnpG);
	AF_INIT_S(VRul, 0x5652756Cu, bool);
	AF_INIT_S(LGui, 0x4C477569u, bool);
	AF_INIT_S(VAll, 0x56416C6Cu, bool);
	AF_INIT_S(VGui, 0x56477569u, bool);
	AF_INIT_S(VMar, 0x564D6172u, bool);
	AF_INIT_S(VBld, 0x56426C64u, bool);
	AF_INIT_S(VGrd, 0x56477264u, bool);
	AF_INIT_S(VTxF, 0x56547846u, bool);
	AF_INIT_S(VBlG, 0x56426C47u, bool);
	AF_INIT_S(BlGT, 0x426C4754u, int32_t);
	AF_INIT_S(TxVO, 0x5478564Fu, uint64_t);
	AF_INIT_S(VSpl, 0x5653706Cu, bool);
	AF_INIT_S(ClSp, 0x436C5370u, bool);
	AF_INIT_S(VCGu, 0x56434775u, bool);
	AF_INIT_C(PrpC, 0x50727043u, PTRt);
	AF_INIT_L(SpIg, 0x53704967u, GStr);
	AF_INIT_C(ExRS, 0x45785253u, ExRS);
	AF_INIT_C(TSty, 0x54537479u, TStS);
	AF_INIT_C(TFmR, 0x54466D52u, TBFR);
	AF_INIT_C(TSrO, 0x5453724Fu, TBSO);
	AF_INIT_C(LoOp, 0x4C6F4F70u, LoDO);
	AF_INIT_E(Snap);
	AF_INIT_N(CurS);
	AF_INIT_S(Indx, 0x496E6478u, int32_t);
	AF_INIT_E(SprC);
	AF_INIT_S(Rest, 0x52657374u, bool);
	AF_INIT_S(DcSH, 0x44635348u, bool);
	AF_INIT_C(Hist, 0x48697374u, DHis);
	AF_INIT_C(Macr, 0x4D616372u, Macr);
	AF_INIT_C(DCMD, 0x44434D44u, DcMD);
	AF_INIT_C(EBDB, 0x45424442u, ExBB);
	AF_INIT_S(IRPC, 0x49525043u, AffinityReader::EnumT);
	AF_INIT_S(IRNL, 0x49524E4Cu, uint64_t);
	AF_INIT_S(PPTy, 0x50505479u, AffinityReader::EnumT);
	AF_INIT_S(PfTg, 0x50665467u, AffinityReader::EnumT);
	AF_INIT_C(PfPl, 0x5066506Cu, PfPr);
}

AF_STRUCT_INIT(PfPr)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_S(name, 0x6E616D65u, std::string);
	AF_INIT_V(idsl, 0x6964736Cu, AffinityReader::SharedArray<uint32_t>);
}

AF_STRUCT_INIT(PfRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(PgNG)
{
	AF_INIT_BASE(BaseGlys);

	AF_INIT_S(Type, 0x54797065u, int32_t);
}

AF_STRUCT_INIT(PhgB)
{
	AF_INIT_BASE(BaseEffect);

	AF_INIT_S(Ambi, 0x416D6269u, double);
	AF_INIT_S(Diff, 0x44696666u, double);
	AF_INIT_S(Spec, 0x53706563u, double);
	AF_INIT_S(Expo, 0x4578706Fu, double);
	AF_INIT_C(AmbC, 0x416D6243u, HSLA);
	AF_INIT_C(SpeC, 0x53706543u, HSLA);
	AF_INIT_C(Lits, 0x4C697473u, PLiA);
}

AF_STRUCT_INIT(PoRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(PosP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(Post, 0x506F7374u, int32_t);
}

AF_STRUCT_INIT(Pref)
{
	AF_INIT_V(BKey, 0x424B6579u, AffinityReader::SharedArray<std::string>);
	AF_INIT_V(BVal, 0x4256616Cu, AffinityReader::SharedArray<bool>);
	AF_INIT_V(DKey, 0x444B6579u, AffinityReader::SharedArray<std::string>);
	AF_INIT_V(DVal, 0x4456616Cu, AffinityReader::SharedArray<double>);
	AF_INIT_V(IKey, 0x494B6579u, AffinityReader::SharedArray<std::string>);
	AF_INIT_V(IVal, 0x4956616Cu, AffinityReader::SharedArray<int32_t>);
	AF_INIT_V(PKey, 0x504B6579u, AffinityReader::SharedArray<std::string>);
	AF_INIT_X(0x5056616Cu, {
		AF_CASE_X(PVal, 0x49425242u, IBRB);
		AF_CASE_X(PVal, 0x52524272u, RRBr);
	});
}

AF_STRUCT_INIT(Prst)
{
	AF_INIT_S(Name, 0x4E616D65u, std::string);
	AF_INIT_C(Vals, 0x56616C73u, ExCV);
}

AF_STRUCT_INIT(PthT)
{
	AF_INIT_S(Path, 0x50617468u, std::string);
}

AF_STRUCT_INIT(Quad)
{
	AF_INIT_S(X0, 0x58302020u, double);
	AF_INIT_S(X1, 0x58312020u, double);
	AF_INIT_S(X2, 0x58322020u, double);
	AF_INIT_S(X3, 0x58332020u, double);
	AF_INIT_S(Y0, 0x59302020u, double);
	AF_INIT_S(Y1, 0x59312020u, double);
	AF_INIT_S(Y2, 0x59322020u, double);
	AF_INIT_S(Y3, 0x59332020u, double);
}

AF_STRUCT_INIT(RBMI)
{
	AF_INIT_C(Bitm, 0x4269746Du, DyBm);
	AF_INIT_S(Desc, 0x44657363u, std::string);
	AF_INIT_S(Auth, 0x41757468u, bool);
	AF_INIT_S(LOff, 0x4C4F6666u, int32_t);
	AF_INIT_S(TOff, 0x544F6666u, int32_t);
}

AF_STRUCT_INIT(RDF2)
{
	AF_INIT_BASE(BaseFilt);

	AF_INIT_C(Para, 0x50617261u, EDfP);
}

AF_STRUCT_INIT(RGBA)
{
	AF_INIT_BASE(BaseColor);

	AF_INIT_S(v_col, 0x5F636F6Cu, AffinityReader::ColorRGBA);
}

AF_STRUCT_INIT(RGBC)
{
	AF_INIT_BASE(BaseFilt);
}

AF_STRUCT_INIT(RHPC)
{
	AF_INIT_BASE(BaseFilt);

	AF_INIT_S(Mono, 0x4D6F6E6Fu, bool);
}

AF_STRUCT_INIT(RLdC)
{
	AF_INIT_BASE(BaseFilt);

	AF_INIT_S(Inte, 0x496E7465u, double);
	AF_INIT_A(Orig, 0x4F726967u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(RadX, 0x52616458u, double);
	AF_INIT_S(RadY, 0x52616459u, double);
}

AF_STRUCT_INIT(RLig)
{
	AF_INIT_BASE(BaseFilt);

	AF_INIT_C(lpar, 0x6C706172u, LigP);
}

AF_STRUCT_INIT(RRBr)
{
	AF_INIT_BASE(BaseBrush);
}

AF_STRUCT_INIT(RRFC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Indx, 0x496E6478u, uint32_t);
	AF_INIT_M(0x5265706Cu, {
		AF_CASE_M(Repl, 0x46696C47u, FilG);
		AF_CASE_M(Repl, 0x46696C53u, FilS);
	});
}

AF_STRUCT_INIT(RUSC)
{
	AF_INIT_BASE(BaseFilt);

	AF_INIT_S(Fact, 0x46616374u, double);
	AF_INIT_S(Thrs, 0x54687273u, double);
}

AF_STRUCT_INIT(RVgC)
{
	AF_INIT_BASE(BaseFilt);

	AF_INIT_S(Expo, 0x4578706Fu, double);
	AF_INIT_S(Hard, 0x48617264u, double);
	AF_INIT_S(Scal, 0x5363616Cu, double);
	AF_INIT_S(Shap, 0x53686170u, double);
}

AF_STRUCT_INIT(RcRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(Rec)
{
	AF_INIT_S(Scal, 0x5363616Cu, int16_t);
	AF_INIT_S(FnPf, 0x466E5066u, std::string);
	AF_INIT_S(Enbl, 0x456E626Cu, bool);
}

AF_STRUCT_INIT(RecP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(RecH, 0x52656348u, float);
	AF_INIT_S(RecS, 0x52656353u, float);
	AF_INIT_S(RecL, 0x5265634Cu, float);
}

AF_STRUCT_INIT(RegC)
{
	AF_INIT_BASE(BaseColor);
}

AF_STRUCT_INIT(Rstr)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(SBMC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Blen, 0x426C656Eu, AffinityReader::EnumT);
	AF_INIT_S(Pass, 0x50617373u, bool);
	AF_INIT_V(OldB, 0x4F6C6442u, AffinityReader::SharedArray<AffinityReader::EnumT>);
	AF_INIT_V(OldP, 0x4F6C6450u, AffinityReader::SharedArray<bool>);
}

AF_STRUCT_INIT(SCER)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_C(Root, 0x526F6F74u, Sprd);
	AF_INIT_C(OldR, 0x4F6C6452u, Sprd);
	AF_INIT_C(OldS, 0x4F6C6453u, Sele);
	AF_INIT_S(ClSl, 0x436C536Cu, bool);
	AF_INIT_N(Femc);
}

AF_STRUCT_INIT(SCRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(SCoP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(Rela, 0x52656C61u, bool);
}

AF_STRUCT_INIT(SDeC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Desc, 0x44657363u, std::string);
	AF_INIT_V(ODes, 0x4F446573u, AffinityReader::SharedArray<std::string>);
	AF_INIT_S(Chan, 0x4368616Eu, bool);
}

AF_STRUCT_INIT(SF2C)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(FNam, 0x464E616Du, std::string);
	AF_INIT_V(Undo, 0x556E646Fu, AffinityReader::SharedArray<std::string>);
	AF_INIT_V(Redo, 0x5265646Fu, AffinityReader::SharedArray<std::string>);
}

AF_STRUCT_INIT(SGCb)
{
	AF_INIT_S(Azim, 0x417A696Du, double);
	AF_INIT_S(Elev, 0x456C6576u, double);
	AF_INIT_S(Roll, 0x526F6C6Cu, double);
}

AF_STRUCT_INIT(SGrP)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_C(SGrd, 0x53477264u, SnpG);
	AF_INIT_S(Pixl, 0x5069786Cu, bool);
}

AF_STRUCT_INIT(SHRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(SHiP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(ShdA, 0x53686441u, float);
	AF_INIT_S(HigA, 0x48696741u, float);
}

AF_STRUCT_INIT(SItm)
{
	AF_INIT_M(0x4F626A74u, {
		AF_CASE_M(Objt, 0x33444C41u, v_3DLA);
		AF_CASE_M(Objt, 0x42435241u, BCRA);
		AF_CASE_M(Objt, 0x42575241u, BWRA);
		AF_CASE_M(Objt, 0x43425241u, CBRA);
		AF_CASE_M(Objt, 0x434D5241u, CMRA);
		AF_CASE_M(Objt, 0x43505478u, CPTx);
		AF_CASE_M(Objt, 0x43725241u, CrRA);
		AF_CASE_M(Objt, 0x45785241u, ExRA);
		AF_CASE_M(Objt, 0x47725241u, GrRA);
		AF_CASE_M(Objt, 0x47727570u, Grup);
		AF_CASE_M(Objt, 0x48735241u, HsRA);
		AF_CASE_M(Objt, 0x496D674Eu, ImgN);
		AF_CASE_M(Objt, 0x496E5241u, InRA);
		AF_CASE_M(Objt, 0x4C655241u, LeRA);
		AF_CASE_M(Objt, 0x4D527374u, MRst);
		AF_CASE_M(Objt, 0x4F43524Eu, OCRN);
		AF_CASE_M(Objt, 0x50437276u, PCrv);
		AF_CASE_M(Objt, 0x50665241u, PfRA);
		AF_CASE_M(Objt, 0x506F5241u, PoRA);
		AF_CASE_M(Objt, 0x52635241u, RcRA);
		AF_CASE_M(Objt, 0x52737472u, Rstr);
		AF_CASE_M(Objt, 0x53435241u, SCRA);
		AF_CASE_M(Objt, 0x53485241u, SHRA);
		AF_CASE_M(Objt, 0x53505241u, SPRA);
		AF_CASE_M(Objt, 0x53636F70u, Scop);
		AF_CASE_M(Objt, 0x5368704Eu, ShpN);
		AF_CASE_M(Objt, 0x536C6350u, SlcP);
		AF_CASE_M(Objt, 0x536C6963u, Slic);
		AF_CASE_M(Objt, 0x53705441u, SpTA);
		AF_CASE_M(Objt, 0x53707264u, Sprd);
		AF_CASE_M(Objt, 0x54685241u, ThRA);
		AF_CASE_M(Objt, 0x54787441u, TxtA);
		AF_CASE_M(Objt, 0x56625241u, VbRA);
		AF_CASE_M(Objt, 0x57425241u, WBRA);
	});
	AF_INIT_X(0x53756253u, {
		AF_CASE_X(SubS, 0x43764853u, CvHS);
		AF_CASE_X(SubS, 0x54657853u, TexS);
	});
}

AF_STRUCT_INIT(SLAD)
{
	AF_INIT_BASE(BaseDels);

	AF_INIT_C(LstA, 0x4C737441u, LisA);
	AF_INIT_N(SubA);
	AF_INIT_S(UpIn, 0x5570496Eu, bool);
}

AF_STRUCT_INIT(SLsC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Mask, 0x4D61736Bu, int32_t);
	AF_INIT_C(Line, 0x4C696E65u, LSty);
	AF_INIT_L(LSty, 0x4C537479u, LDsc);
	AF_INIT_L(OPen, 0x4F50656Eu, FDsc);
	AF_INIT_E(OGly);
}

AF_STRUCT_INIT(SNAR)
{
	AF_INIT_S(AlnX, 0x416C6E58u, int32_t);
	AF_INIT_S(AlnY, 0x416C6E59u, int32_t);
	AF_INIT_S(BndX, 0x426E6458u, int32_t);
	AF_INIT_S(BndY, 0x426E6459u, int32_t);
	AF_INIT_A(Offs, 0x4F666673u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(FPre, 0x46507265u, bool);
	AF_INIT_S(SclT, 0x53636C54u, int32_t);
	AF_INIT_S(Base, 0x42617365u, int32_t);
	AF_INIT_S(Scal, 0x5363616Cu, double);
	AF_INIT_S(IPre, 0x49507265u, bool);
}

AF_STRUCT_INIT(SNEN)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(SNRR)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(SPPp)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_C(Shpe, 0x53687065u, SPst);
}

AF_STRUCT_INIT(SPRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(SPst)
{
	AF_INIT_M(0x53687065u, {
		AF_CASE_M(Shpe, 0x53684345u, ShCE);
		AF_CASE_M(Shpe, 0x53684352u, ShCR);
		AF_CASE_M(Shpe, 0x53684367u, ShCg);
		AF_CASE_M(Shpe, 0x5368436Cu, ShCl);
		AF_CASE_M(Shpe, 0x53684372u, ShCr);
		AF_CASE_M(Shpe, 0x53684441u, ShDA);
		AF_CASE_M(Shpe, 0x53684453u, ShDS);
		AF_CASE_M(Shpe, 0x53684874u, ShHt);
		AF_CASE_M(Shpe, 0x53684E52u, ShNR);
		AF_CASE_M(Shpe, 0x53685069u, ShPi);
		AF_CASE_M(Shpe, 0x53685079u, ShPy);
		AF_CASE_M(Shpe, 0x53685353u, ShSS);
		AF_CASE_M(Shpe, 0x53685367u, ShSg);
		AF_CASE_M(Shpe, 0x53685374u, ShSt);
		AF_CASE_M(Shpe, 0x53685472u, ShTr);
		AF_CASE_M(Shpe, 0x5368547Au, ShTz);
		AF_CASE_M(Shpe, 0x53687044u, ShpD);
		AF_CASE_M(Shpe, 0x53687054u, ShpT);
	});
}

AF_STRUCT_INIT(SRBr)
{
	AF_INIT_BASE(BaseBrush);
}

AF_STRUCT_INIT(SRst)
{
	AF_INIT_S(TrCn, 0x5472436Eu, int32_t);
	AF_INIT_S(TrAn, 0x5472416Eu, AffinityReader::EnumT);
	AF_INIT_A(TrFP, 0x54724650u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(TrFV, 0x54724656u, bool);
	AF_INIT_S(Blnd, 0x426C6E64u, AffinityReader::EnumT);
	AF_INIT_S(PasT, 0x50617354u, bool);
	AF_INIT_C(BlRa, 0x426C5261u, BlnR);
	AF_INIT_A(Xfrm, 0x5866726Du, AffinityReader::vec_d_t<6>, 6);
	AF_INIT_A(SrBx, 0x53724278u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_A(SrPB, 0x53725042u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_A(FTxS, 0x46547853u, AffinityReader::vec_d_t<6>, 6);
	AF_INIT_S(Desc, 0x44657363u, std::string);
	AF_INIT_S(DefD, 0x44656644u, std::string);
	AF_INIT_N(TagC);
	AF_INIT_S(Visi, 0x56697369u, bool);
	AF_INIT_S(Opac, 0x4F706163u, float);
	AF_INIT_S(FOpc, 0x464F7063u, float);
	AF_INIT_E(FiEf);
	AF_INIT_S(Edtb, 0x45647462u, bool);
	AF_INIT_S(CEdb, 0x43456462u, bool);
	AF_INIT_S(MEtb, 0x4D457462u, bool);
	AF_INIT_N(Data);
	AF_INIT_V(Frst, 0x46727374u, AffinityReader::SharedArray<std::string>);
	AF_INIT_V(Scnd, 0x53636E64u, AffinityReader::SharedArray<std::string>);
	AF_INIT_S(Hyty, 0x48797479u, AffinityReader::EnumT);
	AF_INIT_S(Hypr, 0x48797072u, std::string);
	AF_INIT_S(HyTr, 0x48795472u, AffinityReader::EnumT);
	AF_INIT_S(TWSt, 0x54575374u, AffinityReader::EnumT);
	AF_INIT_A(TWBo, 0x5457426Fu, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_S(CLiT, 0x434C6954u, AffinityReader::EnumT);
	AF_INIT_C(Bitm, 0x4269746Du, DyBm);
	AF_INIT_A(BitR, 0x42697452u, AffinityReader::vec_i_t<4>, 4);
	AF_INIT_A(BitI, 0x42697449u, AffinityReader::vec_i_t<4>, 4);
	AF_INIT_S(CMsk, 0x434D736Bu, int32_t);
	AF_INIT_S(ProT, 0x50726F54u, AffinityReader::EnumT);
	AF_INIT_N(Unpr);
	AF_INIT_C(WRot, 0x57526F74u, Matx);
	AF_INIT_S(Lati, 0x4C617469u, double);
	AF_INIT_S(Long, 0x4C6F6E67u, double);
	AF_INIT_S(Roll, 0x526F6C6Cu, double);
	AF_INIT_S(FOV, 0x464F5620u, double);
	AF_INIT_C(Pspv, 0x50737076u, Quad);
	AF_INIT_C(Psp_42, 0x5073702Au, Per_42);
	AF_INIT_S(ExtE, 0x45787445u, bool);
	AF_INIT_S(TraC, 0x54726143u, int32_t);
}

AF_STRUCT_INIT(SSAR)
{
	AF_INIT_S(Indx, 0x496E6478u, int32_t);
	AF_INIT_S(Item, 0x4974656Du, AffinityReader::EnumT);
}

AF_STRUCT_INIT(SSAS)
{
	AF_INIT_L(Runs, 0x52756E73u, SSAR);
}

AF_STRUCT_INIT(SSFH)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_N(OldS);
	AF_INIT_L(OldF, 0x4F6C6446u, FDsc);
	AF_INIT_L(NewF, 0x4E657746u, FDsc);
	AF_INIT_L(NewG, 0x4E657747u, GlAS);
}

AF_STRUCT_INIT(SSLF)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_N(OldS);
	AF_INIT_L(OldF, 0x4F6C6446u, FDsc);
	AF_INIT_L(NewF, 0x4E657746u, FDsc);
	AF_INIT_E(NewG);
}

AF_STRUCT_INIT(SSNS)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(TesC, 0x54657343u, bool);
	AF_INIT_S(ETxt, 0x45547874u, bool);
	AF_INIT_C(OldS, 0x4F6C6453u, Sele);
}

AF_STRUCT_INIT(SSaC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Alig, 0x416C6967u, int32_t);
	AF_INIT_E(OldS);
}

AF_STRUCT_INIT(STPa)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(HlHu, 0x486C4875u, float);
	AF_INIT_S(HlSa, 0x486C5361u, float);
	AF_INIT_S(ShHu, 0x53684875u, float);
	AF_INIT_S(ShSa, 0x53685361u, float);
	AF_INIT_S(Bala, 0x42616C61u, float);
}

AF_STRUCT_INIT(SViC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Mode, 0x4D6F6465u, AffinityReader::EnumT);
	AF_INIT_S(Visi, 0x56697369u, bool);
	AF_INIT_V(OVis, 0x4F566973u, AffinityReader::SharedArray<bool>);
}

AF_STRUCT_INIT(ScAN)
{
	AF_INIT_BASE(BaseScObjs);
}

AF_STRUCT_INIT(ScIN)
{
	AF_INIT_BASE(BaseScObjs);

	AF_INIT_M(0x69706E64u, {
		AF_CASE_M(ipnd, 0x47727570u, Grup);
		AF_CASE_M(ipnd, 0x50437276u, PCrv);
		AF_CASE_M(ipnd, 0x52737472u, Rstr);
		AF_CASE_M(ipnd, 0x53636F70u, Scop);
		AF_CASE_M(ipnd, 0x5368704Eu, ShpN);
		AF_CASE_M(ipnd, 0x54787441u, TxtA);
		AF_CASE_M(ipnd, 0x57425241u, WBRA);
	});
}

AF_STRUCT_INIT(ScPr)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_V(unbr, 0x756E6272u, AffinityReader::SharedArray<int32_t>);
	AF_INIT_S(Dire, 0x44697265u, AffinityReader::EnumT);
	AF_INIT_S(Prev, 0x50726576u, bool);
	AF_INIT_S(ArtC, 0x41727443u, bool);
	AF_INIT_S(AAtC, 0x41417443u, bool);
	AF_INIT_S(CArC, 0x43417243u, bool);
	AF_INIT_S(Stac, 0x53746163u, bool);
	AF_INIT_X(0x4F626A73u, {
		AF_CASE_X(Objs, 0x5363414Eu, ScAN);
		AF_CASE_X(Objs, 0x5363494Eu, ScIN);
		AF_CASE_X(Objs, 0x5363524Eu, ScRN);
	});
	AF_INIT_S(Prog, 0x50726F67u, bool);
	AF_INIT_S(GnHT, 0x476E4854u, bool);
	AF_INIT_S(DIdx, 0x44496478u, int32_t);
}

AF_STRUCT_INIT(ScRN)
{
	AF_INIT_BASE(BaseScObjs);

	AF_INIT_S(shdt, 0x73686474u, AffinityReader::EnumT);
	AF_INIT_M(0x6F6C7072u, {
		AF_CASE_M(olpr, 0x47727570u, Grup);
		AF_CASE_M(olpr, 0x5368704Eu, ShpN);
		AF_CASE_M(olpr, 0x53707264u, Sprd);
	});
	AF_INIT_M(0x6F6C6E73u, {
		AF_CASE_M(olns, 0x47727570u, Grup);
		AF_CASE_M(olns, 0x50437276u, PCrv);
		AF_CASE_M(olns, 0x52737472u, Rstr);
		AF_CASE_M(olns, 0x5368704Eu, ShpN);
	});
	AF_INIT_S(olct, 0x6F6C6374u, AffinityReader::EnumT);
	AF_INIT_C(dtcm, 0x6474636Du, DeSy);
}

AF_STRUCT_INIT(Scal)
{
	AF_INIT_C(ExSc, 0x45785363u, ExSc);
	AF_INIT_S(Path, 0x50617468u, std::string);
	AF_INIT_S(ODPI, 0x4F445049u, double);
}

AF_STRUCT_INIT(Scop)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(VExp, 0x56457870u, bool);
	AF_INIT_M(0x53474E63u, {
		AF_CASE_M(SGNc, 0x48534C41u, HSLA);
		AF_CASE_M(SGNc, 0x52474241u, RGBA);
	});
}

AF_STRUCT_INIT(Sctn)
{
	AF_INIT_S(Head, 0x48656164u, std::string);
	AF_INIT_S(Body, 0x426F6479u, std::string);
	AF_INIT_S(Pst, 0x50737420u, std::string);
	AF_INIT_S(LPst, 0x4C507374u, std::string);
	AF_INIT_S(Foot, 0x466F6F74u, std::string);
	AF_INIT_S(RevO, 0x5265764Fu, bool);
}

AF_STRUCT_INIT(Sele)
{
	AF_INIT_L(Itms, 0x49746D73u, SItm);
	AF_INIT_M(0x4C617972u, {
		AF_CASE_M(Layr, 0x53636F70u, Scop);
		AF_CASE_M(Layr, 0x5368704Eu, ShpN);
		AF_CASE_M(Layr, 0x53707264u, Sprd);
	});
	AF_INIT_S(InRi, 0x496E5269u, bool);
}

AF_STRUCT_INIT(SetE)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_S(Edit, 0x45646974u, bool);
	AF_INIT_C(OldS, 0x4F6C6453u, Sele);
	AF_INIT_V(OlDS, 0x4F6C4453u, AffinityReader::SharedArray<AffinityReader::EnumT>);
}

AF_STRUCT_INIT(ShCE)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(TlAn, 0x546C416Eu, float);
}

AF_STRUCT_INIT(ShCR)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(TlWd, 0x546C5764u, float);
	AF_INIT_S(TlRP, 0x546C5250u, float);
}

AF_STRUCT_INIT(ShCg)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Hole, 0x486F6C65u, float);
	AF_INIT_S(TtSz, 0x5474537Au, float);
	AF_INIT_S(NtSz, 0x4E74537Au, float);
	AF_INIT_S(Teth, 0x54657468u, uint16_t);
}

AF_STRUCT_INIT(ShCl)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Bubl, 0x4275626Cu, uint16_t);
}

AF_STRUCT_INIT(ShCr)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(ArcL, 0x4172634Cu, float);
	AF_INIT_S(ArcR, 0x41726352u, float);
}

AF_STRUCT_INIT(ShDA)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Thck, 0x5468636Bu, float);
	AF_INIT_S(LSty, 0x4C537479u, AffinityReader::EnumT);
	AF_INIT_S(RSty, 0x52537479u, AffinityReader::EnumT);
	AF_INIT_S(LLnk, 0x4C4C6E6Bu, bool);
	AF_INIT_S(LPr1, 0x4C507231u, float);
	AF_INIT_S(LPr2, 0x4C507232u, float);
	AF_INIT_S(RLnk, 0x524C6E6Bu, bool);
	AF_INIT_S(RPr1, 0x52507231u, float);
	AF_INIT_S(RPr2, 0x52507232u, float);
}

AF_STRUCT_INIT(ShDS)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(PRad, 0x50526164u, float);
}

AF_STRUCT_INIT(ShHt)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Sprd, 0x53707264u, float);
}

AF_STRUCT_INIT(ShNR)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(AbS_123, 0x4162537Bu, bool);
	AF_INIT_V(CTyp, 0x43547970u, AffinityReader::SharedArray<AffinityReader::EnumT>);
}

AF_STRUCT_INIT(ShPi)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(AngS, 0x416E6753u, float);
	AF_INIT_S(AngE, 0x416E6745u, float);
}

AF_STRUCT_INIT(ShPy)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Smth, 0x536D7468u, bool);
}

AF_STRUCT_INIT(ShRN)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(ShRR)
{
	AF_INIT_BASE(BaseShape);
}

AF_STRUCT_INIT(ShSS)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(COut, 0x434F7574u, float);
}

AF_STRUCT_INIT(ShSg)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Angl, 0x416E676Cu, float);
	AF_INIT_S(Pos0, 0x506F7330u, float);
	AF_INIT_S(Pos1, 0x506F7331u, float);
}

AF_STRUCT_INIT(ShSt)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(CrcI, 0x43726349u, float);
	AF_INIT_S(CrcO, 0x4372634Fu, float);
	AF_INIT_S(CrvL, 0x4372764Cu, float);
	AF_INIT_S(CrvR, 0x43727652u, float);
	AF_INIT_S(Pntt, 0x506E7474u, uint16_t);
	AF_INIT_S(Lgcy, 0x4C676379u, bool);
}

AF_STRUCT_INIT(ShTr)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(Fixd, 0x46697864u, bool);
	AF_INIT_S(Ball, 0x42616C6Cu, float);
	AF_INIT_S(Bend, 0x42656E64u, float);
	AF_INIT_S(Tail, 0x5461696Cu, float);
}

AF_STRUCT_INIT(ShTz)
{
	AF_INIT_BASE(BaseShape);

	AF_INIT_S(PosL, 0x506F734Cu, float);
	AF_INIT_S(PosR, 0x506F7352u, float);
	AF_INIT_S(PosS, 0x506F7353u, float);
}

AF_STRUCT_INIT(Shad)
{
	AF_INIT_BASE(BaseEffect);

	AF_INIT_S(Knck, 0x4B6E636Bu, bool);
}

AF_STRUCT_INIT(ShpD)
{
	AF_INIT_BASE(BaseShape);
}

AF_STRUCT_INIT(ShpE)
{
	AF_INIT_BASE(BaseShape);
}

AF_STRUCT_INIT(ShpN)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_C(ShpM, 0x5368704Du, ShpN);
	AF_INIT_A(CExR, 0x43457852u, AffinityReader::vec_i_t<4>, 4);
	AF_INIT_A(Orgn, 0x4F72676Eu, AffinityReader::vec_d_t<2>, 2);
}

AF_STRUCT_INIT(ShpT)
{
	AF_INIT_BASE(BaseShape);
}

AF_STRUCT_INIT(SlcP)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(EmMd, 0x456D4D64u, bool);
	AF_INIT_S(InBl, 0x496E426Cu, bool);
	AF_INIT_A(SRct, 0x53526374u, AffinityReader::vec_i_t<4>, 4);
	AF_INIT_L(Slcs, 0x536C6373u, Slic);
	AF_INIT_S(Init, 0x496E6974u, bool);
	AF_INIT_M(0x45784F70u, {
		AF_CASE_M(ExOp, 0x454F506Eu, EOPn);
		AF_CASE_M(ExOp, 0x4645784Fu, FExO);
	});
}

AF_STRUCT_INIT(Slic)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_A(Rect, 0x52656374u, AffinityReader::vec_i_t<4>, 4);
}

AF_STRUCT_INIT(Smps)
{
	AF_INIT_S(smTy, 0x736D5479u, AffinityReader::EnumT);
	AF_INIT_A(smPt, 0x736D5074u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(smVi, 0x736D5669u, bool);
}

AF_STRUCT_INIT(SnpG)
{
	AF_INIT_S(Siz0, 0x53697A30u, double);
	AF_INIT_S(Gut0, 0x47757430u, double);
	AF_INIT_S(Dvs0, 0x44767330u, int32_t);
	AF_INIT_S(Siz1, 0x53697A31u, double);
	AF_INIT_S(Gut1, 0x47757431u, double);
	AF_INIT_S(Dvs1, 0x44767331u, int32_t);
	AF_INIT_S(Siz2, 0x53697A32u, double);
	AF_INIT_S(Gut2, 0x47757432u, double);
	AF_INIT_S(Dvs2, 0x44767332u, int32_t);
	AF_INIT_S(Mode, 0x4D6F6465u, AffinityReader::EnumT);
	AF_INIT_S(Unfm, 0x556E666Du, bool);
	AF_INIT_S(AUpA, 0x41557041u, bool);
	AF_INIT_S(FxAs, 0x46784173u, bool);
	AF_INIT_S(AspR, 0x41737052u, double);
	AF_INIT_S(UAsR, 0x55417352u, double);
	AF_INIT_S(Ang0, 0x416E6730u, double);
	AF_INIT_S(Ang1, 0x416E6731u, double);
	AF_INIT_S(AngU, 0x416E6755u, double);
	AF_INIT_S(Horz, 0x486F727Au, AffinityReader::EnumT);
	AF_INIT_S(Vert, 0x56657274u, AffinityReader::EnumT);
	AF_INIT_S(Intm, 0x496E746Du, AffinityReader::EnumT);
	AF_INIT_S(UpRl, 0x5570526Cu, AffinityReader::EnumT);
	AF_INIT_S(IDvs, 0x49447673u, uint32_t);
	AF_INIT_C(Cube, 0x43756265u, SGCb);
	AF_INIT_N(CRot);
	AF_INIT_S(CScl, 0x4353636Cu, double);
}

AF_STRUCT_INIT(SoPP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_C(Prof, 0x50726F66u, ICCP);
	AF_INIT_S(Intn, 0x496E746Eu, AffinityReader::EnumT);
	AF_INIT_S(BPCs, 0x42504373u, bool);
	AF_INIT_S(SPGC, 0x53504743u, bool);
}

AF_STRUCT_INIT(SpRV)
{
	AF_INIT_L(Rcts, 0x52637473u, SpRe);
}

AF_STRUCT_INIT(SpRe)
{
	AF_INIT_A(Rect, 0x52656374u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_C(Sprd, 0x53707264u, Sprd);
}

AF_STRUCT_INIT(SpTA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(Spln)
{
	AF_INIT_S(Cnt, 0x436E7420u, int32_t);
	AF_INIT_V(Vals, 0x56616C73u, AffinityReader::SharedArray<double>);
	AF_INIT_S(Linr, 0x4C696E72u, bool);
	AF_INIT_S(Bnd1, 0x426E6431u, double);
	AF_INIT_S(BndN, 0x426E644Eu, double);
}

AF_STRUCT_INIT(Sprd)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(PagC, 0x50616743u, int32_t);
	AF_INIT_S(PagF, 0x50616746u, bool);
	AF_INIT_S(PagD, 0x50616744u, bool);
	AF_INIT_A(SprB, 0x53707242u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_S(SprT, 0x53707254u, bool);
	AF_INIT_C(RasS, 0x52617353u, SRst);
	AF_INIT_C(Ras2, 0x52617332u, SRst);
	AF_INIT_A(bled, 0x626C6564u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_C(SlcP, 0x536C6350u, SlcP);
	AF_INIT_C(BgrC, 0x42677243u, RGBA);
	AF_INIT_L(smps, 0x736D7073u, Smps);
	AF_INIT_L(VPts, 0x56507473u, VwPD);
	AF_INIT_S(Fcng, 0x46636E67u, bool);
	AF_INIT_S(R1st, 0x52317374u, bool);
	AF_INIT_C(bbxs, 0x62627873u, PBxR);
	AF_INIT_A(Mrgn, 0x4D72676Eu, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_A(UOrg, 0x554F7267u, AffinityReader::vec_d_t<2>, 2);
}

AF_STRUCT_INIT(StBl)
{
	AF_INIT_C(Glyp, 0x476C7970u, GStr);
	AF_INIT_C(GAtt, 0x47417474u, GlAS);
	AF_INIT_C(PAtt, 0x50417474u, PaAS);
}

AF_STRUCT_INIT(StkN)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_S(SOpe, 0x534F7065u, AffinityReader::EnumT);
}

AF_STRUCT_INIT(Stop)
{
	AF_INIT_S(Posn, 0x506F736Eu, double);
	AF_INIT_S(Type, 0x54797065u, AffinityReader::EnumT);
	AF_INIT_S(Lead, 0x4C656164u, AffinityReader::EnumT);
	AF_INIT_C(LStr, 0x4C537472u, GStr);
	AF_INIT_C(DGly, 0x44476C79u, ChGl);
	AF_INIT_S(FRgh, 0x46526768u, bool);
	AF_INIT_C(IStr, 0x49537472u, TxtA);
	AF_INIT_C(GSel, 0x4753656Cu, TexS);
	AF_INIT_C(PSel, 0x5053656Cu, TexS);
}

AF_STRUCT_INIT(Strk)
{
	AF_INIT_BASE(BaseEffect);

	AF_INIT_S(Alig, 0x416C6967u, AffinityReader::EnumT);
	AF_INIT_S(Ftyp, 0x46747970u, AffinityReader::EnumT);
}

AF_STRUCT_INIT(Stry)
{
	AF_INIT_L(Blok, 0x426C6F6Bu, StBl);
	AF_INIT_S(iTab, 0x69546162u, bool);
}

AF_STRUCT_INIT(TBFR)
{
	AF_INIT_L(fmts, 0x666D7473u, TbFt);
}

AF_STRUCT_INIT(TBSO)
{
	AF_INIT_S(InHd, 0x496E4864u, bool);
	AF_INIT_S(CsSn, 0x4373536Eu, bool);
	AF_INIT_S(NAWd, 0x4E415764u, bool);
}

AF_STRUCT_INIT(TCel)
{
	AF_INIT_S(AliY, 0x416C6959u, AffinityReader::EnumT);
	AF_INIT_A(Inse, 0x496E7365u, AffinityReader::vec_d_t<4>, 4);
}

AF_STRUCT_INIT(TCls)
{
	AF_INIT_A(Size, 0x53697A65u, AffinityReader::vec_i_t<2>, 2);
	AF_INIT_L(Cell, 0x43656C6Cu, TCel);
}

AF_STRUCT_INIT(TEdg)
{
	AF_INIT_C(Line, 0x4C696E65u, LDsc);
	AF_INIT_C(Fill, 0x46696C6Cu, FDsc);
}

AF_STRUCT_INIT(TEds)
{
	AF_INIT_A(Size, 0x53697A65u, AffinityReader::vec_i_t<2>, 2);
	AF_INIT_L(Edge, 0x45646765u, TEdg);
}

AF_STRUCT_INIT(TExM)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_S(TExl, 0x5445786Cu, std::string);
}

AF_STRUCT_INIT(TMpP)
{
	AF_INIT_S(Strg, 0x53747267u, double);
	AF_INIT_S(LocC, 0x4C6F6343u, double);
	AF_INIT_S(ShaI, 0x53686149u, double);
	AF_INIT_S(HigI, 0x48696749u, double);
	AF_INIT_S(SHiE, 0x53486945u, bool);
	AF_INIT_S(Expo, 0x4578706Fu, double);
	AF_INIT_S(ExpE, 0x45787045u, bool);
	AF_INIT_S(Cont, 0x436F6E74u, double);
	AF_INIT_S(ConE, 0x436F6E45u, bool);
	AF_INIT_S(Satu, 0x53617475u, double);
	AF_INIT_S(Vibr, 0x56696272u, double);
	AF_INIT_S(Blap, 0x426C6170u, double);
	AF_INIT_S(Whip, 0x57686970u, double);
	AF_INIT_S(WhiB, 0x57686942u, double);
	AF_INIT_S(Tint, 0x54696E74u, double);
	AF_INIT_S(WhBE, 0x57684245u, bool);
	AF_INIT_S(DRRd, 0x44525264u, double);
	AF_INIT_S(DRAm, 0x4452416Du, double);
	AF_INIT_S(DREn, 0x4452456Eu, bool);
	AF_INIT_C(Curv, 0x43757276u, CrvP);
	AF_INIT_S(CrEn, 0x4372456Eu, bool);
}

AF_STRUCT_INIT(TPos)
{
	AF_INIT_V(Posn, 0x506F736Eu, AffinityReader::SharedArray<double>);
	AF_INIT_V(MSiz, 0x4D53697Au, AffinityReader::SharedArray<double>);
}

AF_STRUCT_INIT(TStS)
{
	AF_INIT_L(Styl, 0x5374796Cu, TSty);
}

AF_STRUCT_INIT(TSty)
{
	AF_INIT_S(Name, 0x4E616D65u, std::string);
	AF_INIT_S(Type, 0x54797065u, AffinityReader::EnumT);
	AF_INIT_S(Show, 0x53686F77u, bool);
	AF_INIT_C(Delt, 0x44656C74u, CoDe);
	AF_INIT_S(Base, 0x42617365u, std::string);
	AF_INIT_S(Foll, 0x466F6C6Cu, std::string);
	AF_INIT_S(Next, 0x4E657874u, std::string);
}

AF_STRUCT_INIT(TabS)
{
	AF_INIT_BASE(BaseAtt);

	AF_INIT_L(Stop, 0x53746F70u, Stop);
	AF_INIT_C(DecG, 0x44656347u, ChGl);
}

AF_STRUCT_INIT(Tabl)
{
	AF_INIT_C(CPos, 0x43506F73u, TPos);
	AF_INIT_C(RPos, 0x52506F73u, TPos);
	AF_INIT_C(CEdg, 0x43456467u, TEds);
	AF_INIT_C(REdg, 0x52456467u, TEds);
	AF_INIT_C(Cell, 0x43656C6Cu, TCls);
	AF_INIT_C(TFmt, 0x54466D74u, TbFt);
	AF_INIT_A(Inst, 0x496E7374u, AffinityReader::vec_d_t<4>, 4);
}

AF_STRUCT_INIT(TbBF)
{
	AF_INIT_C(Fill, 0x46696C6Cu, FDsc);
	AF_INIT_C(LSty, 0x4C537479u, LDsc);
}

AF_STRUCT_INIT(TbCF)
{
	AF_INIT_S(Name, 0x4E616D65u, std::string);
	AF_INIT_L(Brds, 0x42726473u, TbBF);
	AF_INIT_C(Fill, 0x46696C6Cu, FDsc);
	AF_INIT_S(PSty, 0x50537479u, std::string);
	AF_INIT_A(Inst, 0x496E7374u, AffinityReader::vec_d_t<4>, 4);
	AF_INIT_S(AlnY, 0x416C6E59u, AffinityReader::EnumT);
}

AF_STRUCT_INIT(TbFr)
{
	AF_INIT_BASE(BaseFrms);

	AF_INIT_C(Tabl, 0x5461626Cu, Tabl);
}

AF_STRUCT_INIT(TbFt)
{
	AF_INIT_L(Clls, 0x436C6C73u, TbCF);
	AF_INIT_L(Fmts, 0x466D7473u, TbCF);
	AF_INIT_A(Size, 0x53697A65u, AffinityReader::vec_i_t<2>, 2);
	AF_INIT_A(Brds, 0x42726473u, AffinityReader::vec_i_t<4>, 4);
	AF_INIT_S(Name, 0x4E616D65u, std::string);
	AF_INIT_S(ppi, 0x70706920u, double);
	AF_INIT_S(IsDf, 0x49734466u, bool);
	AF_INIT_C(Fill, 0x46696C6Cu, FDsc);
	AF_INIT_C(LFll, 0x4C466C6Cu, FDsc);
	AF_INIT_C(LSty, 0x4C537479u, LDsc);
	AF_INIT_A(Inst, 0x496E7374u, AffinityReader::vec_d_t<4>, 4);
}

AF_STRUCT_INIT(TexS)
{
	AF_INIT_BASE(BaseSubSel);

	AF_INIT_S(SAnc, 0x53416E63u, int32_t);
	AF_INIT_S(SCar, 0x53436172u, int32_t);
	AF_INIT_S(SACF, 0x53414346u, bool);
	AF_INIT_S(SCCF, 0x53434346u, bool);
	AF_INIT_S(SmSp, 0x536D5370u, bool);
}

AF_STRUCT_INIT(ThRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(ThrP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(Thre, 0x54687265u, float);
	AF_INIT_S(Fals, 0x46616C73u, float);
	AF_INIT_S(True, 0x54727565u, float);
}

AF_STRUCT_INIT(TocA)
{
	AF_INIT_BASE(BaseAtt);
}

AF_STRUCT_INIT(TonP)
{
	AF_INIT_BASE(BaseProp);

	AF_INIT_C(Para, 0x50617261u, TMpP);
}

AF_STRUCT_INIT(TrCm)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_E(UndR);
	AF_INIT_S(TrRS, 0x54725253u, bool);
	AF_INIT_S(FTxS, 0x46547853u, bool);
	AF_INIT_A(Xfrm, 0x5866726Du, AffinityReader::vec_d_t<6>, 6);
	AF_INIT_A(ORST, 0x4F525354u, AffinityReader::vec_d_t<6>, 6);
	AF_INIT_A(NotT, 0x4E6F7454u, AffinityReader::vec_d_t<6>, 6);
	AF_INIT_C(OIRe, 0x4F495265u, SpRV);
	AF_INIT_C(NIRe, 0x4E495265u, SpRV);
	AF_INIT_V(OTCn, 0x4F54436Eu, AffinityReader::SharedArray<uint32_t>);
	AF_INIT_V(OTAn, 0x4F54416Eu, AffinityReader::SharedArray<AffinityReader::EnumT>);
	AF_INIT_S(PPFP, 0x50504650u, bool);
	AF_INIT_V(OldA, 0x4F6C6441u, AffinityReader::SharedArray<AffinityReader::vec_d_t<6>>);
	AF_INIT_V(OFTS, 0x4F465453u, AffinityReader::SharedArray<AffinityReader::vec_d_t<6>>);
	AF_INIT_S(Merg, 0x4D657267u, bool);
	AF_INIT_S(CRas, 0x43526173u, bool);
	AF_INIT_S(CorC, 0x436F7243u, bool);
	AF_INIT_V(OlCT, 0x4F6C4354u, AffinityReader::SharedArray<AffinityReader::vec_d_t<6>>);
	AF_INIT_V(OPCT, 0x4F504354u, AffinityReader::SharedArray<AffinityReader::vec_d_t<6>>);
	AF_INIT_S(RArt, 0x52417274u, bool);
	AF_INIT_S(AjPF, 0x416A5046u, bool);
	AF_INIT_S(DupN, 0x4475704Eu, bool);
	AF_INIT_C(DupC, 0x44757043u, Dupl);
	AF_INIT_N(PFPC);
	AF_INIT_C(MovC, 0x4D6F7643u, MvNC);
	AF_INIT_C(RpSd, 0x52705364u, Sprd);
	AF_INIT_N(SCSC);
	AF_INIT_N(SCsC);
}

AF_STRUCT_INIT(TrSl)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_L(Slcs, 0x536C6373u, Slic);
	AF_INIT_E(Nods);
	AF_INIT_A(Ofst, 0x4F667374u, AffinityReader::vec_i_t<2>, 2);
	AF_INIT_S(Mthd, 0x4D746864u, AffinityReader::EnumT);
}

AF_STRUCT_INIT(TxFU) {}

AF_STRUCT_INIT(TxFl)
{
	AF_INIT_X(0x4E6F6473u, {
		AF_CASE_X(Nods, 0x43505478u, CPTx);
		AF_CASE_X(Nods, 0x54787441u, TxtA);
		AF_CASE_X(Nods, 0x54787446u, TxtF);
		AF_CASE_X(Nods, 0x54787454u, TxtT);
	});
	AF_INIT_S(HOvr, 0x484F7672u, bool);
	AF_INIT_C(TFLK, 0x54464C4Bu, ILTf);
}

AF_STRUCT_INIT(TxtA)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_A(bbox, 0x62626F78u, AffinityReader::vec_d_t<4>, 4);
}

AF_STRUCT_INIT(TxtF)
{
	AF_INIT_BASE(BaseLayer);

	AF_INIT_C(StMa, 0x53744D61u, TxtF);
	AF_INIT_L(WSCh, 0x57534368u, PCrv);
	AF_INIT_S(bflp, 0x62666C70u, bool);
}

AF_STRUCT_INIT(TxtT)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(UVCn)
{
	AF_INIT_S(UPPI, 0x55505049u, double);
	AF_INIT_S(SPxM, 0x5350784Du, int32_t);
	AF_INIT_S(VDPI, 0x56445049u, double);
}

AF_STRUCT_INIT(UnSR)
{
	AF_INIT_S(BegI, 0x42656749u, int32_t);
	AF_INIT_S(EndI, 0x456E6449u, int32_t);
}

AF_STRUCT_INIT(UndR)
{
	AF_INIT_S(Fetr, 0x46657472u, uint32_t);
	AF_INIT_S(Valu, 0x56616C75u, int32_t);
}

AF_STRUCT_INIT(Undo)
{
	AF_INIT_C(On, 0x4F6E2020u, v_CB4);
	AF_INIT_C(Off, 0x4F666620u, v_CB5);
}

AF_STRUCT_INIT(VbRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(VibP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(Vibr, 0x56696272u, int32_t);
	AF_INIT_S(Satu, 0x53617475u, float);
}

AF_STRUCT_INIT(VwPD)
{
	AF_INIT_S(vpFr, 0x76704672u, double);
	AF_INIT_A(vpCt, 0x76704374u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_S(vpPn, 0x7670506Eu, std::string);
	AF_INIT_S(vpSI, 0x76705349u, uint32_t);
	AF_INIT_S(vpIM, 0x7670494Du, bool);
}

AF_STRUCT_INIT(WBRA)
{
	AF_INIT_BASE(BaseLayer);
}

AF_STRUCT_INIT(WhBP)
{
	AF_INIT_BASE(BaseAdjustment);

	AF_INIT_S(WhBa, 0x57684261u, int32_t);
	AF_INIT_S(WBTi, 0x57425469u, float);
	AF_INIT_S(WhBV, 0x57684256u, uint16_t);
}

AF_STRUCT_INIT(XCfg)
{
	AF_INIT_L(Fmts, 0x466D7473u, ExCm);
	AF_INIT_S(Path, 0x50617468u, std::string);
}

AF_STRUCT_INIT(XMgC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_L(Undo, 0x556E646Fu, XCfg);
	AF_INIT_E(Redo);
	AF_INIT_S(Chgs, 0x43686773u, AffinityReader::FlagsT);
}

AF_STRUCT_INIT(XStC)
{
	AF_INIT_BASE(BaseCmd);

	AF_INIT_L(Undo, 0x556E646Fu, XCfg);
	AF_INIT_E(Redo);
}

AF_STRUCT_INIT(v_CB1)
{
	AF_INIT_S(byte, 0x62797465u, uint8_t);
	AF_INIT_S(size, 0x73697A65u, uint32_t);
	AF_INIT_L(list, 0x6C697374u, v_C1);
}

AF_STRUCT_INIT(v_CB2)
{
	AF_INIT_S(byte, 0x62797465u, uint8_t);
	AF_INIT_L(list, 0x6C697374u, v_C2);
}

AF_STRUCT_INIT(v_CB3)
{
	AF_INIT_S(byte, 0x62797465u, uint8_t);
	AF_INIT_S(bool_v, 0x626F6F6Cu, bool);
	AF_INIT_V(crvs, 0x63727673u, AffinityReader::SharedArray<AffinityReader::curve18_t>);
}

AF_STRUCT_INIT(v_CB4)
{
	AF_INIT_S(byte, 0x62797465u, uint8_t);
	AF_INIT_S(int_v, 0x696E7420u, uint32_t);
	AF_INIT_A(vecd, 0x76656364u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_A(veci, 0x76656369u, AffinityReader::vec_i_t<2>, 2);
	AF_INIT_S(enum_v, 0x656E756Du, AffinityReader::EnumT);
}

AF_STRUCT_INIT(v_CB5)
{
	AF_INIT_S(byte, 0x62797465u, uint8_t);
	AF_INIT_S(int_v, 0x696E7420u, uint32_t);
	AF_INIT_A(vcd1, 0x76636431u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_A(vci1, 0x76636931u, AffinityReader::vec_i_t<2>, 2);
	AF_INIT_A(vcd2, 0x76636432u, AffinityReader::vec_d_t<2>, 2);
	AF_INIT_A(vci2, 0x76636932u, AffinityReader::vec_i_t<2>, 2);
}

AF_STRUCT_INIT(v_C1)
{
	AF_INIT_S(bool_v, 0x626F6F6Cu, bool);
	AF_INIT_V(crvs, 0x63727673u, AffinityReader::SharedArray<AffinityReader::curve18_t>);
}

AF_STRUCT_INIT(v_C2)
{
	AF_INIT_V(ints, 0x696E7473u, AffinityReader::SharedArray<int32_t>);
	AF_INIT_V(dbls, 0x64626C73u, AffinityReader::SharedArray<double>);
	AF_INIT_V(byts, 0x62797473u, AffinityReader::SharedArray<uint8_t>);
}

} // namespace AffinityReader::CppModel
